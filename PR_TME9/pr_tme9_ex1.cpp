//
// Created by root on 03/01/19.
//


#include <iostream>
#include <mutex>
#include <condition_variable>
#include <cstring>
#include <thread>

#define SIZE_PIPE 5

using namespace std;

class Pipe {

    char vect[SIZE_PIPE];
    int read_offset , write_offset;
    int nb_char;

    mutex m;
    condition_variable cv;

public:

    Pipe() : read_offset(0) , write_offset(0) , nb_char(0) {}

    /**
     * Read at most n char from the pipe
     * If the pipe contains less than n char, then all the char are read
     * If the pipe is empty, the thread falls asleep until a writing is done
     * @param buf
     * @param n
     * @return the number of char read
     */
    int read(char *buf , int n) {
        unique_lock<mutex> lk(m);
        cv.wait(lk , [&] () {return nb_char != 0;});

        int nb_read = 0;

        for(int i=read_offset , j=0 ; nb_char && j<n ; i = (i+1) % SIZE_PIPE , j++ , nb_char-- , nb_read++) {
            buf[j] = vect[i];
        }

        return nb_read;
    }

    /**
     * Write n char in the pipe if the space is available. Otherwise return -1 and do nothing.
     * @param buf
     * @param n
     * @return
     */
    int write(char *buf , int n) {
        unique_lock<mutex> lk(m);

        if(SIZE_PIPE - nb_char < n) return -1;

        size_t space_tail = SIZE_PIPE - (size_t)write_offset;

        if(space_tail > n) {
            memcpy(vect+write_offset , buf ,(size_t)n);
        }
        else {
            memcpy(vect + write_offset , buf , space_tail);
            memcpy(vect , buf+space_tail , n-space_tail);
        }

        nb_char += n;
        write_offset = (write_offset + n) % SIZE_PIPE;

        cv.notify_all();

        return n;
    }

};

/* **************************************************************************************************************************** */

Pipe pipe;

void thread_read() {
    int size_buf = 3;
    char buf[size_buf];
    int nb_read = pipe.read(buf , size_buf);

    cout << nb_read << " char read : ";
    for(int i=0 ; i<size_buf ; i++) cout << buf[i] << " ";
}

void thread_write() {
    char to_write[] = {'a' , 'b' , 'c'};

    int nb_write = pipe.write(to_write , 3);
    cout << "nb_write : " << nb_write << endl;

    this_thread::yield();

    nb_write = pipe.write(to_write , 3);
    cout << "nb_write : " << nb_write << endl;
}

int main() {

    thread thread_reading(thread_read);
    thread thread_writing(thread_write);

    thread_writing.join();
    thread_reading.join();
}
