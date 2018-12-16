//
// Created by root on 05/10/18.
//

#ifndef PR_TME2_VECTOR_H
#define PR_TME2_VECTOR_H

#include <cstddef>
#include <iostream>

#define DEFAULT_ALLOC_SIZE 10U

namespace micky {

    template <typename T>
    class Vector {

        size_t nb_element;
        size_t size_alloc;
        T * tab;

        typedef T* iterator;
        typedef const T* const_iterator;

    public:

        Vector(size_t s_alloc = DEFAULT_ALLOC_SIZE) {
            nb_element = 0;
            size_alloc = s_alloc;
            tab = new T[size_alloc];
        }

        ~Vector() {
            delete[] tab;
        }

        const T& operator[](size_t index) const {
            if(index < 0 || index >= nb_element) {
                std::cerr << "Try to access an invalid index !!";
            }

            return *(tab+index);
        }


        T& operator[](size_t index) {
            if(index < 0 || index >= nb_element) {
                std::cerr << "Try to access an invalid index";
            }

            return *(tab+index);
        }

        size_t size() {
            return nb_element;
        }

        size_t size_Alloc() {
            return size_alloc;
        }

        bool empty() {
            return (nb_element == 0);
        }

        void push_back(const T& value) {
            ensureSize(nb_element + 1);
            *(tab+nb_element) = value;
            nb_element++;
        }

        void ensureSize(size_t wish) {
            if(wish <= size_alloc) return;

            T *temp = new T[size_alloc*2];

            for(size_t i=0; i<nb_element ; i++)
                *(temp+i) = *(tab+i);

            size_alloc *= 2;
            delete[] tab;
            tab = temp;
        }

        iterator begin() {
            return tab;
        }

        iterator end() {
            return tab+nb_element;
        }

        void display() {
            std::cout << "Size_alloc : " << size_alloc << std::endl;
            std::cout << "Nb_elements : " << nb_element << std::endl;
            std::cout << "***** Content *****" << std::endl;
            for(size_t i=0 ; i<nb_element ; i++)
                std::cout << "Index : " << i << "\tValue : " << *(tab+i) << std::endl;

        }


    };
}

#endif //PR_TME2_VECTOR_H
