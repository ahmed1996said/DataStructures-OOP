//
// Created by Ahmed Al Mahrooqi on 2019-04-18.
//

#ifndef ECE309_SPR19_GRAPH_H
#define ECE309_SPR19_GRAPH_H

#include "List.h"
class Graph {
protected:
    int numNodes;
    bool directed;

public:
    Graph(int n, bool isDirected = false) : numNodes(n), directed(isDirected){};
    virtual void addEdge(int, int) = 0;
    virtual bool isEdge(int, int) = 0;
    virtual int maxConnection(){return 0;}
    virtual List findPath(int,int){List a;return a; }
    int nodes() { return numNodes; }
    int isAdjacent(int a, int b) { return isEdge(a, b); }
    virtual List getAdjacencyList(int n) = 0;
    bool isPath(List v);  // given list of vertices, is it a path?
    bool isDirected() { return directed; }

};

//-----------------------------------------

class SparseGraph : public Graph {
protected:
    class Node {
    public:
        List edges;
    };
    Node *nodes;  // adjacency list

public:
    SparseGraph(int n, bool isDirected = false);
    void addEdge(int, int) override;
    bool isEdge(int, int) override;
    List findPath(int,int) override;
    List getAdjacencyList(int) override;
};

//-----------------------------------------

class DenseGraph : public Graph {
    bool *edges;  // adjacency matrix

public:
    DenseGraph(int n, bool isDirected = false);
    void addEdge(int, int) override;
    bool isEdge(int, int) override;
    List getAdjacencyList(int) override;
    int maxConnection() override ;
};

//----------------------------------------
// BFS function and class
//----------------------------------------

// function returns list of nodes in BFS order
List BreadthFirstSearch(Graph& g, int start);

class GraphBFS {
protected:
    Graph &g;
public:
    GraphBFS(Graph &graph) : g(graph) {}
    void run(int start);
    virtual void visit(int node) { }  // does nothing unless overridden
};

class BFSList : public GraphBFS {
private:
    List nodes;
public:
    void visit(int node) override { nodes.append(node); }
};

//---------------------------------------
// DFS function and class
//---------------------------------------

// function returns list of nodes in DFS order
List DepthFirstSearch(Graph &g, int start);

class GraphDFS {
protected:
    Graph &g;
public:
    GraphDFS(Graph &graph) : g(graph) {}
    void run(int start);
    virtual void visit(int node) {}  // does nothing unless overridden
};

//----------------------------------------
// Topological Sort of a directed graph
//----------------------------------------

List TopologicalSort(Graph& g);

#endif //ECE309_SPR19_GRAPH_H
