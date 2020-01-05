//
// Created by Ahmed Al Mahrooqi on 2019-02-24.
//

#ifndef ECE309_SPR19_INTHASHTABLE_H
#define ECE309_SPR19_INTHASHTABLE_H

// Closed hash table of integers with linear probing
// data and key are identical

class IntHashTable {

private:
    enum Status {empty_since_start, empty_removed, full};
    class Bucket {
    public:
        int data;
        Status status;
        Bucket() : data(0), status(empty_since_start) {}
        void fill(int x) { data = x; status = full; }
        void remove() { data = 0; status = empty_removed; }
        int key() { return data; }
    };

    unsigned int size;
    Bucket* buckets;
    unsigned int hash(int key) { return key % size;}
    bool find(int key, unsigned int& index);

public:
    class iterator {
    private:
        Bucket* b;
        int pos;
        int length;

    public:
       iterator(Bucket *bk,int l){b = bk; pos=0; length=l;}                     // take size parameter

        int getData();                    // returns data item referenced by this BSTiterator
        void increment();
        iterator& operator++();
        bool end();                                 // returns true if BSTiterator has moved past the last item
        friend class IntHashTable;

    };


    IntHashTable(unsigned int s = 0) : size(s), buckets(nullptr) {
        if (size > 0) {
            buckets = new Bucket[size];
        }
    }
    ~IntHashTable() {
        delete [] buckets;
    }


    bool insert(int item);
    bool search(int key, int& item);
    bool peek(int key);
    bool remove(int key);
    iterator begin();

    bool resize(unsigned int new_size);

};



#endif //ECE309_SPR19_INTHASHTABLE_H
