//
// Created by Ahmed Al Mahrooqi on 2019-02-26.
//
/*
#include "EmployeeDirectory.h"


bool EmployeeDirectory::insert(Employee e) {
    unsigned int h = hash(e.last_name);
    List& bucket = buckets[h];
    // this version does not check for duplicates
    // inconsistent with other hash table, but simpler code

    Employee copy_e = e;

    bucket.append(copy_e);
    return true;

}


bool EmployeeDirectory::find(const char* key, List::iterator& iter) {
    unsigned int h = hash(key);
    iter = buckets[h].begin();
    bool found = false;
    while (!iter.end()) {
        found = (iter.getEmployee().last_name == key);
        if (found) break;
        iter.increment();
    }
    return found;
}

const Employee* EmployeeDirectory::search(const char* key, Employee& e) {
    List::iterator it;
    bool found = find(key, it);
    if (found) {
        e = it.getEmployee();
        return &e;  //return address of employee
    }
    else
     return nullptr;
}


bool EmployeeDirectory::peek(const char* key) {
    List::iterator dummy;
    return find(key, dummy);
}

bool EmployeeDirectory::remove(const char* key) {
    List::iterator it;
    Employee e;
    bool found = find(key, it);
    if (found) {
        // redundant calculation of hash
        // could avoid by repeating code from find(..)
        buckets[hash(key)].removeAt(it, e);
    }

    //delete

    return found;
}


unsigned int EmployeeDirectory::hash(const char *key){        //key is last_name

    int init = 5381;
    int m = 33;
    int h;

    h=init;

    for(int i=0;i< key[i]!='\0';i++){
        h = (h*m)+ key[i];
    }

    return h%size;
}
*/