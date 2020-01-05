//
// Created by Ahmed Al Mahrooqi on 2019-01-31.
//

#ifndef ECE309_SPR19_PARENMATCHER_H
#define ECE309_SPR19_PARENMATCHER_H

#include "CharStack.h"
#include <cstdio>


class ParenMatcher : private CharStack{




    public:

    ParenMatcher() : CharStack() {}
    ~ParenMatcher();
    bool check(const char *);




};




#endif //ECE309_SPR19_PARENMATCHER_H
