//
// Created by Ahmed Al Mahrooqi on 2019-04-18.
//

#ifndef ECE309_SPR19_QUEUE_H
#define ECE309_SPR19_QUEUE_H

#include "List.h"

class Queue {
private:
    List list;

public:
    Queue() {}
    void push(Item);
    void pop();
    Item& peek();
    bool empty();
};


#endif //ECE309_SPR19_QUEUE_H
