#include <iostream>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <cstring>
#include <unistd.h>
#include <wait.h>
#include <sys/stat.h>
#include <errno.h>


#define SIZE_BUFFER 50

using namespace std;

int i, n=6;
int pid;

sem_t *semRead1 , *semRead2 , *semWrite;


void send(char *buf) {
    const char *msg[] = {"Je" , "suis" , "un" , "vilain" , "programme" , "\n"};
    for(i=0 ; i<n ; i++) {
        sem_wait(semWrite);
        sem_wait(semWrite);

        strcpy(buf , msg[i]);

        sem_post(semRead1);
        sem_post(semRead2);
    }
    exit(0);
}

void receive(char *buf) {
    if((pid = fork()) == -1) {
        perror("Error fork in receive");
        exit(EXIT_FAILURE);
    }

    for(i=0 ; i<n ; i++) {
        if(pid == 0) sem_wait(semRead1);
        else sem_wait(semRead2);

        if(pid != 0) cout << "\t";
        else cout << "\t\t\t\t\t";

        cout << buf << endl;
        sem_post(semWrite);
    }

}

int main() {

    semRead1 = sem_open("/semRead1" , O_CREAT , 0666 , 0);
    semRead2 = sem_open("/semRead2" , O_CREAT , 0666 , 0);
    semWrite = sem_open("/semWrite" , O_CREAT , 0666 , 2);


    char *shared = (char*) mmap(nullptr , SIZE_BUFFER , PROT_READ | PROT_WRITE , MAP_SHARED | MAP_ANONYMOUS , -1 , 0);
    if(shared == MAP_FAILED) {
        perror("Error mmap");
        exit(EXIT_FAILURE);
    }

    if((pid = fork()) == -1) {
        perror("Error fork in main");
        exit(EXIT_FAILURE);
    }
    if(pid == 0) receive(shared);
    else send(shared);

    if(pid == 0) exit(0);
    for(i=0 ; i<2 ; i++) wait(nullptr);

    sem_unlink("/semRead1");
    sem_unlink("/semRead2");
    sem_unlink("/semWrite");
    munmap(shared , SIZE_BUFFER);

    cout << "\n*** End program ***" << endl;


    return 0;
}