//
// Created by Ahmed Al Mahrooqi on 2019-03-26.
//
#include "IntMaxHeap.h"
#include "gtest/gtest.h"


TEST(heap, allfunctions) {

    IntMaxHeap heap;

    int out;

    EXPECT_TRUE(heap.empty());

    heap.insert(20);
    heap.insert(1);
    heap.insert(150);
    heap.insert(100);
    heap.insert(2);
    heap.insert(24);
    heap.insert(25);
    heap.insert(26);
    heap.insert(207);

    EXPECT_FALSE(heap.empty());

    heap.remove(out);
    EXPECT_EQ(out,207);

    heap.remove(out);
    EXPECT_EQ(out,150);

    heap.remove(out);
    EXPECT_EQ(out,100);

    heap.remove(out);
    EXPECT_EQ(out,26);

    EXPECT_EQ(heap.peek(),25);

    //remove everything, test empty()
    heap.remove(out);
    heap.remove(out);
    heap.remove(out);
    heap.remove(out);
    heap.remove(out);

    EXPECT_FALSE(heap.remove(out));         //removing from empty tree
    EXPECT_TRUE(heap.empty());


}


TEST(heap, fiftyInserts) {

    IntMaxHeap heap;
    int out;

    EXPECT_TRUE(heap.empty());


    for(int i =50;i>=0;i--){
        heap.insert(i);
    }
    EXPECT_TRUE(heap.remove(out));
    EXPECT_EQ(out,50);



}