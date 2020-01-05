//
// Created by Ahmed Al Mahrooqi on 2019-03-22.
//

#ifndef ECE309_SPR19_POINTERSSTACK_H
#define ECE309_SPR19_POINTERSSTACK_H

#include "List.h"

class Stack {
private:
    List list;

public:
    Stack() {}
    void push(Item);
    void pop();
    Item &peek();
    bool empty();
};

//create another .h file for BTNode
/*
template <class X>
class Stack{

public:
    class StackNode{
    private:
        X* node;
        StackNode* next;
    public:
        StackNode(X* n = nullptr,StackNode* nxt= nullptr): node(n), next(nxt){}
        X* getAddress(){return node;}
        StackNode* getNext(){return next;}
    };

    StackNode* head;
    StackNode* tail;
    int length;


    Stack();
    ~Stack();   // destructor
    void push(X* p);
    bool pop(X*& out);
    bool empty();
    int size();

};


template<class X>
Stack<X>::Stack() { head= nullptr; tail= nullptr; length=0;}


template<class X>
Stack<X>::~Stack() {X* bstnode; while(pop(bstnode));}

template<class X>
void Stack<X>::push(X* p) {
    auto newNode = new StackNode(p,head);   //set next item of new item to head of current stack


    if(head == nullptr)                      // if the stack is empty, set tail to the new item
        tail=newNode;


    head=newNode;
    length++;
}


template<class X>
bool Stack<X>::pop(X* &out) {        // pop character from stack if non-empty;

    if(empty()){
        return false;
    }

    auto tmp=head;                     // save address of current head
    out  = head->getAddress();            // save address
    head = head->getNext();            // update head to next item on stack
    if(head== nullptr)                 // check if stack empty
        tail= nullptr;

    delete tmp;
    length--;
    return true;
}

template<class X>
bool Stack<X>::empty() {  // return true if empty, false if not empty{
    return head == nullptr;
}

template<class X>
int Stack<X>::size() {  return length; }




*/

#endif //ECE309_SPR19_POINTERSSTACK_H
