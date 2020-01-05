//
// Created by Ahmed Al Mahrooqi on 2019-01-27.
//
#include "CharStack.h"

CharStack::CharStack(){
    head= nullptr;
    tail= nullptr;
    numChars=0;
    charNode i;
}

CharStack::~CharStack() {
    char d;
    while(pop(d));
}

bool CharStack::empty() {
    return head == nullptr;

}

void CharStack::push(char c){


    auto newNode = new charNode(c,head);    //set next item of new item to head of current stack

    if(head == nullptr)                      // if the stack is empty, set tail to the new item
        tail=newNode;

    head=newNode;
    numChars++;
}

bool CharStack::pop(char &out){

    if(empty()){
        return false;
    }


    auto tmp=head;                     // save address of current head
    out  = head->getChar();            // save character
    head = head->getNext();            // update head to next item on stack
    if(head== nullptr)                 // check if stack empty
        tail= nullptr;

    delete tmp;
    numChars--;
    return true;

}

bool CharStack::peek(char &out) {

    if(empty()) {return false;}

    out=head->getChar();
    return true;
}

int CharStack::length(){
    return numChars;

}



