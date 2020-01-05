//
// Created by Ahmed Al Mahrooqi on 2019-02-28.
//

#ifndef ECE309_SPR19_LIST_H
#define ECE309_SPR19_LIST_H

/*
class Employee {
public:
    const char*  last_name;
    const char* first_name;
    const char* title;
    const char* office;
    const char* phone;

    Employee(const char* l,const char* f,const char* t,const char* o,const char* p):last_name(l), first_name(f),title(t),office(o),phone(p) {}
    Employee():last_name(), first_name(),title(),office(),phone() {}
};

// List class -- will implement as a singly-linked list
class List {
private:
    // ListNode class to hold items in the list
    class ListNode {
    private:
        Employee employee;
        ListNode * next;
    public:
        ListNode(Employee e, ListNode* n = nullptr) {
            employee = e;
            next = n;
        }
        ListNode *getNext() { return next; }
        void setNext(ListNode *ptr) { next = ptr; }
        Employee getEmployee() {return employee;}
    };

    // head and tail pointers
    ListNode* head;
    ListNode* tail;
public:
    // BSTiterator class to traverse list nodes
    class iterator {
    private:
        ListNode *node;   // points to a specific node in the list
    public:
        iterator(ListNode* n = nullptr) { node = n; }  // constructor
        Employee getEmployee() { return node->getEmployee(); }
        void increment() { node = node->getNext(); }
        bool end() { return node == nullptr; }

        friend class List;
    };

    List();
    ~List();
    bool empty();
    void append(const Employee& a);
    bool remove(Employee& a);
    // changed from removeAfter to removeAt for hash table
    bool removeAt(iterator, Employee&);
    iterator begin() { return iterator(head); }
};

*/




#include <stdio.h>

using Item = int;

class List {
private:
    // ListNode represents each
    // node of the list
    class ListNode {
    public:
        Item item; // data in the list
        ListNode *next;

    public:
        ListNode(Item a, ListNode *n = NULL) {
            item = a;
            next = n; // automatically serves as a list tail
        }
        ListNode *getNext() { return next; }
        void setNext(ListNode *n) { next = n; }
        Item &getItem() { return item; }
    };

    // add head and tail pointer
    ListNode *head;
    ListNode *tail;

public:
    class iterator {
    private:
        ListNode *node;

    public:
        iterator(ListNode *n = NULL) { node = n; }
        Item &getItem() { return node->getItem(); }
        void increment() { node = node->next; }
        bool end() { return node == NULL; }

        friend class List;
    };

public:
    List();
    List(const List &copy);

    void append(Item a);
    bool remove(Item &a);
    bool empty();

    iterator begin() { return iterator(head); }

    void removeAfter(iterator it); // pseudocode in zyBook 2.4
    void insertAfter(iterator it, Item item);
};


#endif //ECE309_SPR19_LIST_H
