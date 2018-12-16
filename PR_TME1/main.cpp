#include <iostream>
#include "StringUtil.h"
#include "String.h"
#include "StringPtr.h"

int main() {

    const char *text = "toto";

    std::cout << "text : " << text << "\t" << "length : " << micky::length(text) << std::endl;

    char *textcopy = micky::newcopy(text);

    std::cout << "text copy : " << textcopy << "\t" << "length : " << micky::length(textcopy) << std::endl;

    delete[] (textcopy);

//***************************************************************************************************

    micky::String string1("bonjour");
    micky::String string2(string1);
    micky::String string3("bon");
    micky::String string4("manger");

    std::cout << "String 1 : " << string1 << "\t" << "length : " << string1.length() << std::endl;
    std::cout << "String 2 : " << string2 << "\t" << "length : " << string2.length()  << std::endl;

    std::cout << "Comparaison string1 et string2 : " << ( (!(string1 == string2)) ? "Egales" : "Differentes" ) << std::endl;
    std::cout << "Comparaison string1 et string3 : " << ( (!(string1 == string3)) ? "Egales" : "Differentes" ) << std::endl;
    std::cout << "Comparaison string1 et string4 : " << ( (!(string1 == string4)) ? "Egales" : "Differentes" ) << std::endl;

    std::cout << "string1 " << ((string1 < string2) ? "<" : ">=") << " string 2" << std::endl;
    std::cout << "string1 " << ((string1 < string3) ? "<" : ">=") << " string 3" << std::endl;
    std::cout << "string1 " << ((string1 < string4) ? "<" : ">=") << " string 4" << std::endl;

    std::cout << "string1 at [2] : " << string1[2] << std::endl;
    std::cout << "string1 at [-2] : " << string1[-2] << std::endl; // test error
    std::cout << "string1 at [10] : " << string1[10] << std::endl; // test error

    micky::String string5 = string1 + string2;
    micky::String string6 = string1 + string3;

    std::cout << "string1 + string2 : " <<  string5 << " length : " << string5.length() << std::endl;
    std::cout << "string1 + string3 : " <<  string6 << " length : " << string6.length() << std::endl;


    micky::StringPtr sPtr1("hello");
    micky::StringPtr sPtr2(sPtr1);

    sPtr1.test();


    //std::cout << "sPtr 1 : " << sPtr1 << std::endl;
    //std::cout << "sPtr 2 : " << sPtr2 << std::endl;







    return 0;
}


