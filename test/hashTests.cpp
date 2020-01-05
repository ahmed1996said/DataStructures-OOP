//
// Created by Ahmed Al Mahrooqi on 2019-02-28.
//

#include "gtest/gtest.h"
#include "IntHashTable.h"
#include "EmployeeDirectory.h"

TEST(inthashtable, iterator_functions) {        //test begin(),end() and increment(), and getData() functions

    IntHashTable t(6);

    t.insert(1);
    t.insert(3);
    t.insert(5);
    int i = -1;


    for(auto it = t.begin(); !it.end(); ++it) {
        i+=2;                                      // produces odd numbers: 1,3,5
        EXPECT_EQ(it.getData(), i );

    }

}

TEST(inthashtable, resize_function) {        //test begin(),end() and increment(), and getData() functions

    IntHashTable t(3);
    t.insert(3);

    auto it = t.begin();


    EXPECT_EQ(it.getData(),3);      //at begining (location 0), the bucket should contain 3 (3%3=0)
    t.resize(5);
    t.insert(0);

    it=t.begin();
    ++it;
    EXPECT_EQ(it.getData(),3);

}




TEST(employeeDirectory, public_functions) {


    EmployeeDirectory d(4);
    Employee e;

    d.insert(Employee("Johns","Adam","Mr.","IT","31881"));
    EXPECT_TRUE(d.search("Johns",e));
    EXPECT_TRUE(d.peek("Johns"));
    EXPECT_EQ(d.search("Johns",e)->first_name,"Adam");

    d.remove("Johns");
    EXPECT_FALSE(d.peek("Johns"));


}