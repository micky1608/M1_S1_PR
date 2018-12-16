//
// Created by root on 29/09/18.
//

#ifndef PR_TME1_STRING_H
#define PR_TME1_STRING_H


#include <cstddef>
#include <iostream>

namespace micky {

    class String {

        friend std::ostream& operator<< (std::ostream& os , const String& string);
        friend bool operator==(const String& s1 , const String& s2);
        friend bool operator<(const String& s1 , const String& s2);
        friend String operator+(const String& s1 , const String& s2);

        const char *s;

        public:

            size_t length() const;

            String(const char *s2);

            String(String& string);

            ~String();

            char operator[](size_t indice) const;

    };

    std::ostream& operator<< (std::ostream& os , const String& string);

    bool operator==(const String& s1 , const String& s2);

    bool operator<(const String& s1 , const String& s2);

    String operator+(const String& s1 , const String& s2);

}

#endif //PR_TME1_STRING_H
