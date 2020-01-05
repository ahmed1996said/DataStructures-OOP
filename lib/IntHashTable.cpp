//
// Created by Ahmed Al Mahrooqi on 2019-02-24.

#include "IntHashTable.h"
#include <cstdio>
#include <cstring>

bool IntHashTable::insert(int item) {
    unsigned int h = hash(item);
    unsigned int i = h;
    while (buckets[i].status == full) {
        if (buckets[i].data == item) return false;  // can't insert twice
        i = (i+1) % size;
        if (i == h) return false;  // table is full
    }
    buckets[i].fill(item);
    return true;
}

bool IntHashTable::find(int key, unsigned int & index) {
    unsigned int h = hash(key);
    unsigned int i = h;
    while ((buckets[i].status == full && buckets[i].data != key)
           || (buckets[i].status == empty_removed)) {
        i = (i+1) % size;
        if (i == h) return false;
    }
    if (buckets[i].status == full) {
        index = i;
        return true;
    }
    return false;
}

bool IntHashTable::search(int key, int& item) {
    unsigned int i;
    bool found = find(key, i);
    if (found) {
        item = buckets[i].data;
        return true;
    }
    return false;
}

bool IntHashTable::peek(int key) {
    unsigned int i;
    return find(key, i);
}

bool IntHashTable::remove(int key) {
    unsigned int i;
    bool found = find(key, i);
    if (!found) return false;
    buckets[i].remove();
    return true;
}

bool IntHashTable::resize(unsigned int new_size) {

    if (new_size <= size)
        return false;
    else {

        int old_size = size;

        size = new_size;

        Bucket *temp = buckets;

        buckets = new Bucket[new_size];

        for (int i = 0; i < old_size; i++)
            insert(temp[i].data);

        delete[] temp;
        return true;

    }
}

IntHashTable::iterator IntHashTable::begin() {

    iterator it(buckets,size);

    if(buckets[0].status!=full)
        it.increment();             // find first non-empty bucket


    return it;

}



IntHashTable::iterator &IntHashTable::iterator::operator++() {
    increment();
    return *this;
}

void IntHashTable::iterator::increment() {

    pos++;

    if(!end()) {

        while (b[pos].status != full && !end()) {
            pos++;
        }
    }


}



int IntHashTable::iterator::getData() {
    return b[pos].data;
}

bool IntHashTable::iterator::end() {

    return pos == length;       //true when position of BSTiterator is past the last item

}