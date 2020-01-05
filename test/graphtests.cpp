//
// Created by Ahmed Al Mahrooqi on 2019-04-18.
//
#include "gtest/gtest.h"
#include "Graph.h"


TEST(graph, maxConnections) {

   DenseGraph g(14);

    g.addEdge(13,8);
    g.addEdge(8,1);
    g.addEdge(1,0);

    g.addEdge(0,2);
    g.addEdge(2,7);
    g.addEdge(7,12);

    g.addEdge(0,3);
    g.addEdge(3,6);
    g.addEdge(6,11);

    g.addEdge(6,5);
    g.addEdge(5,9);
    g.addEdge(3,5);

    g.addEdge(5,4);
    g.addEdge(3,4);
    g.addEdge(4,10);

    EXPECT_EQ(4,g.maxConnection());

}