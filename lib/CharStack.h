//
// Created by Ahmed Al Mahrooqi on 2019-01-27.
//
#ifndef ECE309_SPR19_CHARSTACK_H
#define ECE309_SPR19_CHARSTACK_H

class CharStack {

protected:
    class charNode{
        private:
        char data;
        charNode* next;
        public:
        charNode(char c=0,charNode* n= nullptr){ data=c; next= n;}
        char getChar(){return data;}
        charNode* getNext(){return next;}
    };

    charNode* head;
    charNode* tail;
    int numChars;

public:
    CharStack();    // constructor: create an empty stack
    ~CharStack();   // destructor
    void push(char c);   // push character c onto the stack
    bool pop(char& out); // pop character from stack if non-empty;
    // return true if popped, false if empty
    bool peek(char& out); // copy but do not remove top of stack;
    // return false if empty, true if non-empty
    bool empty();   // return true if empty, false if not empty
    int length();   // return number of characters on the stack

};






#endif //ECE309_SPR19_CHARSTACK_H
