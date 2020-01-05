//
// Created by Ahmed Al Mahrooqi on 2019-04-18.
//

#include "Stack.h"

void Stack::push(Item item)
{
    List::iterator it; // get a NULL iterator
    // the NULL iterator will allow us to insert at the front
    // of the stack:
    list.insertAfter(it,item);
}

void Stack::pop()
{
    List::iterator it; // get a NULL iterator
    // the NULL iterator lets us remove the front of the stack
    list.removeAfter(it);
}

Item& Stack::peek()
{
    List::iterator it = list.begin();
    return it.getItem();
}

bool Stack::empty()
{
    return list.empty();
}