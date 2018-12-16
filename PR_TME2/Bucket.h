//
// Created by root on 06/10/18.
//

#ifndef PR_TME2_BUCKET_H
#define PR_TME2_BUCKET_H

namespace micky {

    template<typename K, typename V>
    struct Bucket {

        const K key;
        V value;

        Bucket(K key, V value) : key(key), value(value) {}


    };
}

#endif //PR_TME2_BUCKET_H
