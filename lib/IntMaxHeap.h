//
// Created by Ahmed Al Mahrooqi on 2019-03-24.
//

#ifndef ECE309_SPR19_INTMAXHEAP_H
#define ECE309_SPR19_INTMAXHEAP_H

#include <stdio.h>

class IntMaxHeap{

    private:
        int size;
        int* array;
        int numItems;

    public:

    IntMaxHeap();
    void insert(int);
    bool remove(int&);
    bool empty();
    int peek();

    void percolateUp(int);
    void percolateDown(int);


};




#endif //ECE309_SPR19_INTMAXHEAP_H

