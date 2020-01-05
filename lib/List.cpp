//
// Created by Ahmed Al Mahrooqi on 2019-02-28.
//

#include <stdio.h>

#include "List.h"
// Hold a string

List::List() {
    // start with an empty list
    head = NULL;
    tail = NULL;
}

List::List(const List &copy) : List() {
    ListNode *tmp = copy.head;
    while (tmp != NULL) {
        append(tmp->getItem());
        tmp = tmp->next;
    }
}

void List::append(Item a) {
    ListNode *node = new ListNode(a);
    if (head == NULL) {
        // list is empty
        head = node;
        tail = node;
    } else {
        tail->setNext(node);
        tail = node;
    }
}

bool List::remove(Item &copy) {
    if (!empty()) // if list is not empty
    {
        copy = head->getItem(); // return copy
        ListNode *tmp = head->getNext();
        delete head;     // delete the node
        head = tmp;      // update the head
        if (tmp == NULL) // removed last element
            tail = NULL;
        return true;
    }
    return false; // nothing in list
}

bool List::empty() { return head == NULL; }

void List::insertAfter(List::iterator it, Item item) // pseudocode in zyBook 2.3
{
    if (it.node == NULL) { // special case to insert at the head
        // point new node at current head of list
        ListNode *node = new ListNode(item, head);
        if (head == NULL) { // if head was NULL, tail was also NULL
            tail = node;      // new node is now the tail
            head = node;      // new node is now the head
        } else {
            head = node; // update head to new node
        }
    } else // insert after it
    {
        ListNode *node = new ListNode(item, it.node->getNext());
        it.node->setNext(node);
        if (tail == it.node)
            tail = node;
    }
}

void List::removeAfter(List::iterator it) // pseudocode in zyBook 2.4
{
    if (it.node == NULL) // special case to remove head, it’s not after any node
    {
        ListNode *remove = head; // will remove the head
        head = head->getNext();  // advance head
        if (head == NULL)
            tail = NULL; // if head is NULL now, list is empty
        delete remove; // delete removed node
    } else // normal case, if not the head, then simply disconnect the node
    {
        ListNode *tmp = it.node;
        ListNode *remove = tmp->getNext(); // next node to be removed
        tmp->setNext(remove->getNext());   // point around node to be removed
        if (tail == remove)
            tail = tmp;  // if removing tail, update tail
        delete remove; // delete node      // delete the removed node
    }
}
/*
// constructor -- create an empty list
List::List() {
    head = nullptr;  // both head and tail are NULL
    tail = nullptr;
}

// if head is NULL, then list is empty
bool List::empty() {
    return head == nullptr;
}

// destructor -- delete all nodes
List::~List() {
    Employee t;
    while (remove(t));
}

// append and item to the end of the list
void List::append(const Employee& a) {
    auto node = new ListNode(a);  // create a new node
    if (head == nullptr) {  // if list is empty, both head and tail point to new node
        head = node;
        tail = node;
    }
    else {  // else, make current tail point to new node
        tail->setNext(node);
        tail = node;  // and update the tail pointer
    }
}

// remove first item in list, return false if empty
bool List::remove(Employee& a) {
    if (!empty()) {
        a = head->getEmployee();  // copy first item to a
        auto tmp = head->getNext();  // point to second node
        delete head;  // delete first node
        head = tmp;   // second node becomes head
        if (head == nullptr) {  // if list is now empty...
            tail = nullptr;     // make sure tail is also NULL
        }
        return true;   // an item was removed, so return true
    }
    else {
        return false;  // list was empty, nothing removed
    }
}

// would be easier with a doubly-linked list
bool List::removeAt(List::iterator it, Employee& e)
{
    ListNode *target = it.node;   // node to be removed
    if (!target) return false;    // nothing removed
    e = target->getEmployee();
    if (target == head) {
        head = target->getNext();
        if (!head) tail = nullptr;
    }
    else {
        ListNode *p = head;
        while (p && p->getNext() != target) p = p->getNext();
        if (!p) return false;  // should never happen because target is non-null
        p->setNext(target->getNext());  // remove target from list
    }
    delete target;
    return true;
}
 */