//
// Created by root on 04/10/18.
//

#ifndef PR_TME1_STRINGPTR_H
#define PR_TME1_STRINGPTR_H


#include <memory>

namespace micky {

    class StringPtr {

        std::shared_ptr<const char> s;

        friend std::ostream& operator<<(std::ostream& os , const StringPtr& stringPtr);

        public:

        StringPtr(StringPtr& stringPtr);

        StringPtr(const char *s2);

        void test();

    };

    std::ostream& operator<<(std::ostream& os , const StringPtr& stringPtr);

}

#endif //PR_TME1_STRINGPTR_H
