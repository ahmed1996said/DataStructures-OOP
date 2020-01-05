//
// Created by Ahmed Al Mahrooqi on 2019-03-21.
//

#ifndef ECE309_SPR19_KVPAIR_H
#define ECE309_SPR19_KVPAIR_H

template <class K, class T>


class KVPair{

public:
    K key;
    T val;

public:
    KVPair(K k, T v){key=k;val=v;}
    K getKey(){return key;}
    T getVal(){return val;}
};





#endif //ECE309_SPR19_KVPAIR_H
