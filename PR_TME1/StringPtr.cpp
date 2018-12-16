//
// Created by root on 04/10/18.
//

#include "StringPtr.h"
#include "StringUtil.h"
#include <cstring>
#include <iostream>

namespace micky {

    StringPtr::StringPtr(const char *s2) {
            s = std::make_shared<const char>(*s2);
    }

    StringPtr::StringPtr(StringPtr& stringPtr) {
        s = stringPtr.s;
    }

    void StringPtr::test() {
        const char *p = s.get();
        while(*p) {
            std::cout << p;
            p++;
        }

    }

    std::ostream& operator<<(std::ostream& os , const StringPtr& stringPtr) {
        os << stringPtr.s.get();
        return os;
    }




}
