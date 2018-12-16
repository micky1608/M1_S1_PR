//
// Created by root on 29/09/18.
//

#include <cstring>
#include "String.h"
#include "StringUtil.h"

namespace micky {

    size_t String::length() const {
        return micky::length(s);
    }

    String::String(const char *s2) {
        s = micky::newcopy(s2);
    }

    String::String(micky::String &string) {
        s = micky::newcopy(string.s);
    }

    String::~String() {
        delete[] s;
    }

    char String::operator[](size_t indice) const {
        if(indice < 0 || indice >= micky::length(s)) {
            std::cout << "!!! Acces à un indice incorrect !!! ";
            return '0';
        }
        return s[indice];
    }

    std::ostream& operator<<(std::ostream& os , const String& string) {
        os << string.s;
        return os;
    }

    bool operator==(const String& s1 , const String& s2) {
        int retour = micky::compare(s1.s,s2.s);
        if(retour) return true;
        return false;
    }

    bool operator<(const String& s1 , const String& s2) {
        if(micky::compare(s1.s,s2.s) < 0)
            return true;
        return false;
    }

    String operator+(const String& s1 , const String& s2) {

        size_t size = s1.length() + s2.length();
        char result[size + 1];
        char *p = result;

        memcpy(p , s1.s , s1.length());
        p += s1.length();
        memcpy(p , s2.s , s2.length());
        result[size] = '\0';

        return String(result);
    }
}
