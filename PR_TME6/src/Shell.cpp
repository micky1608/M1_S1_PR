////
//// Created by root on 21/11/18.
////


#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void shell(int argc , char *argv[]) {

    cout << "\t***** Display arguments *****" << endl;
    cout << "argc : " << argc << endl;

    for(size_t k=0 ; k<argc ; k++) {
        cout << "argv[" << k << "] : " << argv[k] << endl;
    }

    cout << "\n\t***** *****" << endl;

    size_t i=0;

    while(i<argc && strcmp(argv[i],"|") != 0 && strcmp(argv[i],"\\|") != 0) i++;

    if(i == argc) {
        perror("argv must contain the char |");
        exit(-1);
    }

    cout << "\nPipe index = " << i << endl << endl;

    char *argv_first_son[i] , *argv_second_son[argc-i];
    size_t len;

    // Allocate and fill the first array
    for(size_t k=0 ; k<i-1 ; k++) {
        len = strlen(argv[k+1]);
        argv_first_son[k] = new char[len + 1] ;
        strcpy(argv_first_son[k] , argv[k+1]);
        argv_first_son[k][len] = '\0';
    }
    argv_first_son[i-1] = nullptr;

    //Allocate and fill the second array
    for(size_t k=0 ; k<argc-i-1 ; k++) {
        len = strlen(argv[i+k+1]);
        argv_second_son[k] = new char[len + 1];
        strcpy(argv_second_son[k],argv[i+k+1]);
        argv_second_son[k][len] = '\0';
    }
    argv_second_son[argc-i-1] = nullptr;

    //display the first array
    for(size_t k=0 ; k<i ; k++)
        cout << "argv_first_son[" << k <<"] = " << (argv_first_son[k] != nullptr ? argv_first_son[k] : "nullptr") << endl;

    //display the second array
    for(size_t k=0 ; k<argc-i ; k++)
        cout << "argv_second_son[" << k <<"] = " << (argv_second_son[k] != nullptr ? argv_second_son[k] : "nullptr") << endl;

    //pipe creation for the communication between the two sons
    int pipe_fd[2];

    if(pipe(pipe_fd) == -1) {
        perror("Pipe creation error !");
        exit(-2);
    }

    cout << endl << "\t\t********** **********" <<endl;
    // First son creation
    pid_t pid = fork();

    if(pid == -1) {
        fprintf(stderr, "Error first fork");
        exit(-3);
    }

    if(!pid) {

        // close the reading direction of the pipe
        if(close(pipe_fd[0]) == -1) {
            fprintf(stderr ,"Error first son close pipe 0\n");
            exit(-7);
        }

        // redefine the default output file with the pipe
        if(dup2(pipe_fd[1] , STDOUT_FILENO) == -1) {
            fprintf(stderr, "Error first son dup\n");
            exit(-8);
        }

        if(close(pipe_fd[1]) == -1) {
            fprintf(stderr ,"Error first son close pipe 1\n");
            exit(-7);
        }

        if(execv(argv_first_son[0] , argv_first_son) == -1) {
            fprintf(stderr , "First exec error\n");
            exit(-4);
        }
    }

    // wait the end of the first son
    waitpid(pid,nullptr,0);

    // Second son creation
    pid_t pid2 = fork();

    if(pid2 == -1) {
        fprintf(stderr , "Error Second fork");
        exit(-3);
    }

    if(!pid2) {

        // close the writing direction of the pipe
        if(close(pipe_fd[1]) == -1) {
            fprintf(stderr , "Error second son close pipe 1");
            exit(-10);
        }

        // redefine the standard input file with the pipe
        if(dup2(pipe_fd[0] , STDIN_FILENO) == -1) {
            fprintf(stderr,"Error second son dup");
            exit(-11);
        }

        if(close(pipe_fd[0]) == -1) {
            fprintf(stderr ,"Error second son close pipe 0\n");
            exit(-9);
        }

        if(execv(argv_second_son[0] , argv_second_son) == -1) {
            fprintf(stderr , "Error exec second son");
            exit(-12);
        }
    }

    close(pipe_fd[0]);
    close(pipe_fd[1]);

    // Free all the allocated memory
    for(size_t k=0 ; k<i-1 ; k++)           delete[] argv_first_son[k];
    for(size_t k=0 ; k<argc-i-1 ; k++)      delete[] argv_second_son[k];

    exit(0);


}
