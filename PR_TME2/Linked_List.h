//
// Created by root on 05/10/18.
//

#ifndef PR_TME2_LINKED_LIST_H
#define PR_TME2_LINKED_LIST_H

#include <cstddef>
#include <iostream>

namespace micky {

    template <typename T>
    class LinkedList {

        class ChainElement {

        public:

            T data;
            ChainElement *next;

            ChainElement(const T& d , ChainElement *n) : data(d) , next(n) {}



        }; //end ChainElement class



        class Iterator {
            ChainElement *current;

        public :

            Iterator(ChainElement *chainElement) {
                current = chainElement;
            }

            Iterator operator++() {
                current = current->next;
                return *this;
            }

            bool operator!= (Iterator it) {
                return (current != it.current);
            }

            T& operator*() {
                return current -> data;
            }

        };

        ChainElement *head;

    public:

        LinkedList() {
            head = nullptr;
        }

        ~LinkedList() {
            ChainElement *current = head;
            ChainElement *next_current;

            while(current != nullptr) {
                next_current = current->next;
                delete[] current;
                current = next_current;
            }
        }

        size_t size() const {
            size_t count = 0;
            ChainElement *current = head;

            while(current != nullptr) {
                count++;
                current = current->next;
            }
            return count;
        }

        bool empty() {
            return (head == nullptr);
        }

        void push_front(const T& value) {
            ChainElement *chainElement = new ChainElement(value , head);
            head = chainElement;
        }

        void push_back(const T& value) {

            ChainElement *chainElement = new ChainElement(value , nullptr);

            if(empty()) {
                head = chainElement;
            }

            ChainElement *current = head;
            while(current->next != nullptr) current = current->next;

            current->next = chainElement;
        }

        Iterator begin() {
            return Iterator(head);
        }

        Iterator end() {
            return Iterator(nullptr);
        }

        void operator= (LinkedList<T> otherList) {

            ChainElement *current = head;
            ChainElement *next_current;

            while(current != nullptr) {
                next_current = current->next;
                delete[] current;
                current = next_current;
            }

            auto it_otherList = otherList.begin();
            while(it_otherList != otherList.end()) {
                this->push_back(*it_otherList);
                ++it_otherList;
            }
        }


        void display() {
            std::cout << "***** List Content *****" << std::endl;
            ChainElement *current = head;
            while(current != nullptr) {
                std::cout << current-> data << "\t";
                current = current-> next;
            }

            std::cout << "\n";
        }



    };
}

#endif //PR_TME2_LINKED_LIST_H
