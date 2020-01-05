//
// Created by Ahmed Al Mahrooqi on 2019-04-18.
//

#ifndef ECE309_SPR19_INTEGERSET_H
#define ECE309_SPR19_INTEGERSET_H


#include "List.h"

// IntegerSet abstract base class to demonstrate hash table concepts
class IntegerSet {
protected:
    int size;
    int hash(int key) const { return (key * 997) % size; }
public:
    IntegerSet(int htsize):size(htsize) {}
    virtual bool insert(int) = 0;
    virtual bool search(int) const = 0;
    virtual void remove(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
    int *table;
    int probeDistance;
    const int empty_since_start = -2;
    const int empty_after_removal = -1;
public:
    IntegerSetHT(int htsize);
    bool insert(int) override;
    bool search(int) const override;
    void remove(int) override;
};

// Hash Table with Chaining
class IntegerSetHTChain : public IntegerSet {
protected:
    List *table;
public:
    IntegerSetHTChain(int htsize);
    bool insert(int) override;
    bool search(int) const override;
    void remove(int) override;
};


#endif //ECE309_SPR19_INTEGERSET_H
