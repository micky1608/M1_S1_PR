//
// Created by root on 06/10/18.
//

#ifndef PR_TME2_HASH_TABLE_H
#define PR_TME2_HASH_TABLE_H

#include "Bucket.h"
#include "Vector.h"
#include "Linked_List.h"


namespace micky {

    template <typename K , typename V>
    class Hash_Table {

        size_t size;

        Vector<LinkedList<Bucket<K,V>>> buckets;

        class Iterator {

            Vector<LinkedList<Bucket<K,V>>>* table;
            LinkedList<Bucket<K,V>> *currentList;
            Bucket<K,V> *currentBucket;

        public:

            Iterator(Vector<LinkedList<Bucket<K,V>>> *table  , LinkedList<Bucket<K,V>> *currentList , Bucket<K,V> *currentBucket) : table(table) , currentList(currentList) , currentBucket(currentBucket) {}

            Iterator operator++() {
                Bucket<K,V> itList = currentList->begin();
                while(itList != currentBucket) itList++;

                itList++;

                if(itList == currentList->end()) {
                    LinkedList<Bucket<K,V>> *itVector = table->begin();
                    while(itVector != currentList) itVector++;

                    do {
                        itVector++;
                    } while (*itVector->empty() && itVector != table->end());

                    if(itVector != table->end()) {
                        currentList = itVector;
                        currentBucket = currentList->begin();
                    }
                    else {
                        currentList = table->end();
                        currentBucket = nullptr;
                    }
                }
                else {
                    currentBucket = itList;
                }
                return *this;
            }

            bool operator==(Iterator it) {
                return (currentList == it.currentList && currentBucket == it.currentBucket);
            }

            Bucket<K,V>& operator*() {
                return *currentBucket;
            }


        };

    public:

        Hash_Table(size_t size) {
            this->size = size;
            for(size_t i=0 ; i<size ; i++) {
                buckets.push_back(LinkedList<Bucket<K,V>>());
            }
        }


        Iterator begin() {
            size_t i=0;
            while(buckets[i].empty() && i<size) i++;
            if(i<size) return Iterator(&buckets , &buckets[i] , &(*buckets[i].begin()));
            return end();
        }

        Iterator end() {
            return Iterator(&buckets , buckets.end() , nullptr);
        }

        Iterator find (const K& key) {
            size_t h = (std::hash<K>() (key)) % size;
            LinkedList<Bucket<K,V>> list = buckets[h];

            auto it = list.begin();
            while((*it).key != key && it != list.end()) it++;
            if((*it).key == key) return Iterator(&buckets , &list , &(*it));
            return end();
        }

        std::pair<Iterator,bool> insert (Bucket<K,V>& bucket) {

            std::hash<K> hash_fn;
            size_t h = (hash_fn(bucket.key)) % size;

            if(buckets[h].empty()) {
                buckets[h].push_front(bucket);
            }
            else {
               auto listIt = buckets[h].begin();
               while(listIt != buckets[h].end() && (*listIt).key != bucket.key) ++listIt;
               if(listIt != buckets[h].end()) {
                   Iterator it(&buckets , &buckets[h] , &(*listIt));
                   return std::pair<Iterator,bool>(it,false);
               }
                buckets[h].push_back(bucket);
            }

            Iterator iterator(&buckets,&buckets[h],&bucket);
            std::pair<Iterator,bool> pair(iterator,true);
            return pair;
        }



    };

}

#endif //PR_TME2_HASH_TABLE_H
