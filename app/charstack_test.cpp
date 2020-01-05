//
// Created by Ahmed Al Mahrooqi on 2019-02-04.
//

#include "CharStack.h"
#include <cstdio>

int main(){


    CharStack c;
    char out;


    printf("Expected outcome will be put in parentheses\n");
    printf("(0) Length = %d\n",c.length());
    printf("(1) is the list empty? : %d\n",c.empty());
    c.push('d');
    printf("(0) 'd' is pushed is the list empty? : %d\n",c.empty());
    c.push('e');
    c.push('m');
    c.push('h');
    c.push('a');

    printf("(5) e,m,h,a is pushed. Length = %d\n",c.length());
    c.pop(out);
    printf("(a) Pop function called. Item popped: %c\n",out);
    c.peek(out);
    printf("(h) Peek function called. Item : %c\n",out);
    c.pop(out);
    c.pop(out);
    c.pop(out);
    c.pop(out);
    printf("(0,1) All items popped. Length= %d,Empty? : %d\n",c.length(),c.empty());
    printf("(0) Pop empty list. Check return value: %d\n",c.pop(out));



    return 0;
}