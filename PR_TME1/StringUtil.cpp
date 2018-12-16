//
// Created by root on 29/09/18.
//


#include <cstddef>
#include <cstring>
#include <iostream>

namespace micky {

    size_t length(const char *s) {
        const char *s_end = s;
        while(*s_end) s_end++;
        return s_end - s;
    }

    char* newcopy(const char *s) {
        size_t l = micky::length(s);
        char *res = new char[l+1];
        memcpy(res,s,l);
        res[l] = '\0';
        return res;
    }

    int compare(const char *a , const char *b) {
        while(*a) {

            if(!*b) return 1;
            if(*a < *b) return -1;
            if(*a > *b) return 1;

            a++;
            b++;

        }

        if(!*b) return 0;

        return -1;
    }

}