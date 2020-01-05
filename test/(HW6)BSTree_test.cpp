//
// Created by Ahmed Al Mahrooqi on 2019-03-21.
//

#include "gtest/gtest.h"
#include "BSTree.h"
#include <string>

/*
TEST(bst, insertSearchRemove) {
   using std::string;


    BSTree<int,string> tree;

    string w;
    string x;
    string y;
    string z;

    string b("Birds");
    string c("Cats");
    string d("Dogs");
    string e("Elephants");

    EXPECT_FALSE(tree.search(50,x));

    tree.insert(KVPair<int,string>(50,c));
    EXPECT_TRUE(tree.search(50,x));
    EXPECT_EQ(x,c);

    tree.insert(KVPair<int,string>(30,d));  // insert to left
    EXPECT_TRUE(tree.search(30,y));
    EXPECT_EQ(y,d);

    tree.insert(KVPair<int,string>(75,b));  // insert to right
    EXPECT_TRUE(tree.search(50,x));
    EXPECT_TRUE(tree.search(30,y));
    EXPECT_TRUE(tree.search(75,z));
    EXPECT_EQ(z,b);

    EXPECT_FALSE(tree.search(100,x));
    EXPECT_TRUE(tree.search(75,z));
    EXPECT_TRUE(tree.search(30,y));
    EXPECT_FALSE(tree.search(1,z));

    EXPECT_TRUE(tree.remove(50));
    EXPECT_FALSE(tree.search(50,x));
    EXPECT_TRUE(tree.remove(30));
    EXPECT_TRUE(tree.remove(75));

    //search for removed items:
    EXPECT_FALSE(tree.search(50,y));
    EXPECT_FALSE(tree.search(30,z));
    EXPECT_FALSE(tree.search(75,x));

    EXPECT_FALSE(tree.remove(100));  //removing something not in the tree

}



TEST(bst, getheight) {
 using std::string;

 BSTree<int,string> tree;

 string w;
 string x;
 string y;
 string z;

 string b("Birds");
 string c("Cats");
 string d("Dogs");
 string e("Elephants");


 EXPECT_EQ(tree.getHeight(),-1);     //empty tree

 //height= 0
 tree.insert(KVPair<int,string>(50,c));
 EXPECT_EQ(tree.getHeight(),0);

 //height =1
 tree.insert(KVPair<int,string>(70,d));
 tree.insert(KVPair<int,string>(30,b));
 EXPECT_EQ(tree.getHeight(),1);

 //adding stuff to the left, length =4
 tree.insert(KVPair<int,string>(10,d));
 tree.insert(KVPair<int,string>(9,b));
 tree.insert(KVPair<int,string>(8,b));
 EXPECT_EQ(tree.getHeight(),4);


 //add stuff to the right, make it longer than left. height = 5
 tree.insert(KVPair<int,string>(80,d));
 tree.insert(KVPair<int,string>(90,b));
 tree.insert(KVPair<int,string>(95,b));
 tree.insert(KVPair<int,string>(97,b));
 EXPECT_EQ(tree.getHeight(),5);

 //remove everything, height = -1
 tree.remove(80);
 tree.remove(90);
 tree.remove(95);
 tree.remove(97);
 tree.remove(10);
 tree.remove(9);
 tree.remove(8);
 tree.remove(70);
 tree.remove(30);
 tree.remove(50);
 EXPECT_EQ(tree.getHeight(),-1);


}

TEST(BSTiterator, iteratorfunctions){


   BSTree<int,int> tree;



   KVPair<int,int> mypair(5,2);

   tree.insert(KVPair<int,int>(75,1));
   tree.insert(KVPair<int,int>(60,1));
   tree.insert(KVPair<int,int>(80,1));
   tree.insert(KVPair<int,int>(10,1));
   tree.insert(KVPair<int,int>(15,1));
   tree.insert(KVPair<int,int>(12,1));
   tree.insert(KVPair<int,int>(11,1));
   tree.insert(KVPair<int,int>(100,1));
   tree.insert(KVPair<int,int>(90,1));
   tree.insert(KVPair<int,int>(110,1));


      auto i = tree.begin();






      EXPECT_FALSE(i.end());
      EXPECT_EQ(i.getKey(),10);
      i.increment();
     EXPECT_EQ(i.getKey(),11);
      i.increment();
      EXPECT_EQ(i.getKey(),12);
      i.increment();
      EXPECT_EQ(i.getKey(),15);
      i.increment();
      EXPECT_EQ(i.getKey(),60);
      i.increment();
      EXPECT_EQ(i.getKey(),75);
      EXPECT_FALSE(i.end());

      i.increment();
      EXPECT_EQ(i.getKey(),80);
      i.increment();
      EXPECT_EQ(i.getKey(),90);
      i.increment();
      EXPECT_EQ(i.getKey(),100);
      i.increment();
      EXPECT_EQ(i.getKey(),110);
      i.increment();
      EXPECT_TRUE(i.end());












}

*/