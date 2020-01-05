//
// Created by Ahmed Al Mahrooqi on 2019-01-31.
//

#include "ParenMatcher.h"
#include <cstdio>

ParenMatcher::~ParenMatcher() {
    char d;
    while(pop(d));
}

bool ParenMatcher::check(const char *str){

    int i=0;
    char out;

    while(str[i]!='\0'){

        if(str[i]=='(') { push(str[i]); }
        if(str[i]==')') {
            if(!pop(out))
                return false;
        }
        i++;
    }


    while(!empty()){             // if not empty, empty out the stack first then return false
        pop(out);
        return false;
    }


    return true;

}

