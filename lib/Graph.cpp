//
// Created by Ahmed Al Mahrooqi on 2019-04-18.
//

#include "Graph.h"
#include <stdio.h>


#include "Graph.h"
#include "IntegerSet.h"
#include "Queue.h"
#include "Stack.h"
#include <stdio.h>

bool Graph::isPath(List v) {
    if (v.empty()) return false;
    bool path = true;
    List::iterator i = v.begin();
    int prev = i.getItem();
    i.increment();
    while (!i.end()) {
        int next = i.getItem();
        if (!isAdjacent(prev, next)) {
            path = false; break;
        }
        prev = next;
        i.increment();
    }
    return path;
}

//------------------------------------

SparseGraph::SparseGraph(int n, bool dir) : Graph(n,dir) {
    nodes = new Node[numNodes];
}

void SparseGraph::addEdge(int v1, int v2) {
    nodes[v1].edges.append(v2);
    if (!directed) nodes[v2].edges.append(v1);
}

bool SparseGraph::isEdge(int v1, int v2) {
    bool found = false;
    List edges = nodes[v1].edges;
    for (auto it = edges.begin(); !it.end(); it.increment()) {
        if (it.getItem() == v2) {
            found = true; break;
        }
    }
    return found;
}

List SparseGraph::getAdjacencyList(int node) {
    return nodes[node].edges;
}

List SparseGraph::findPath(int, int) {





}

//-------------------------------------

DenseGraph::DenseGraph(int n, bool dir) : Graph(n,dir) {
    edges = new bool[numNodes * numNodes];
    for (int i = 0; i < numNodes * numNodes; i++)
        edges[i] = false;
}
void DenseGraph::addEdge(int v1, int v2) {
    edges[v1 * numNodes + v2] = true;
    if (!directed) edges[v2 * numNodes + v1] = true;
}

bool DenseGraph::isEdge(int v1, int v2) {
    return edges[v1 * numNodes + v2];
}

List DenseGraph::getAdjacencyList(int node) {
    List neighbors;
    int node_row_offset = node * numNodes;  // index of node's edges
    for (int i=0; i < numNodes; i++) {
        if (edges[node_row_offset + i]) neighbors.append(i);
    }
    return neighbors;
}

//-------------------------------------

List BreadthFirstSearch(Graph& g, int start) {
    List nodes;
    IntegerSetHT discoveredSet(1000);
    Queue frontierQueue;
    // initialize -- put start node in frontierQueue and discoveredSet
    frontierQueue.push(start); discoveredSet.insert(start);
    while (!frontierQueue.empty()) {
        int n = frontierQueue.peek();  // get head of queue
        nodes.append(n);   // "visit" by adding to list
        frontierQueue.pop();  // remove from queue
        List adj = g.getAdjacencyList(n);
        List::iterator it = adj.begin();
        // add non-discovered adjacent nodes to discoveredSet and frontierQueue
        while (!it.end()) {
            int j = it.getItem();
            if (!discoveredSet.search(j)) {
                frontierQueue.push(j);
                discoveredSet.insert(j);
            }
            it.increment();
        }
    }
    return nodes;
}

void GraphBFS::run(int start) {
    IntegerSetHT discoveredSet(1000);
    Queue frontierQueue;
    // initialize -- put start node in frontierQueue and discoveredSet
    frontierQueue.push(start); discoveredSet.insert(start);
    while (!frontierQueue.empty()) {
        int n = frontierQueue.peek();  // get head of queue
        visit(n);      // perform visit operation
        frontierQueue.pop();  // remove from queue
        List::iterator it = g.getAdjacencyList(n).begin();
        // add non-discovered adjacent nodes to discoveredSet and frontierQueue
        while (!it.end()) {
            int j = it.getItem();
            if (!discoveredSet.search(j)) {
                frontierQueue.push(j);
                discoveredSet.insert(j);
            }
            it.increment();
        }
    }
}

//---------------------------------------------

void RecursiveDFS(Graph &g, IntegerSet& visited, int node, List& dfsOrder) {
    if (!visited.search(node)) {
        visited.insert(node);
        dfsOrder.append(node);  // "visit" by adding to list
        List adj = g.getAdjacencyList(node);
        for (List::iterator it = adj.begin(); !it.end(); it.increment()) {
            RecursiveDFS(g, visited, it.getItem(), dfsOrder);
        }
    }
}

List DepthFirstSearch(Graph &g, int start) {
    List list;
    IntegerSetHT visited(1000);
    RecursiveDFS(g, visited, start, list);
    return list;
}

//-----------------------------------------------

void RecursiveDFSTopo(Graph &g, IntegerSet& visited, int node, Stack& dfsPostOrder) {
    if (!visited.search(node)) {
        visited.insert(node);
        List adj = g.getAdjacencyList(node);
        for (List::iterator it = adj.begin(); !it.end(); it.increment()) {
            RecursiveDFSTopo(g, visited, it.getItem(), dfsPostOrder);
        }
        dfsPostOrder.push(node);  // post-order visit
    }
}

List TopologicalSort(Graph &g) {
    List topo;
    if (!g.isDirected()) return topo;  // return empty list if undirected
    IntegerSetHT visited(1000);
    Stack dfsPostOrder;

    int maxNode = g.nodes();
    for (int i=0; i < maxNode; i++) {
        if (!visited.search(i)) {
            // look for a non-visited node with no incoming edges
            bool noIncoming = true;
            for (int j = 0; j < maxNode; j++) {
                if ((j != i) && g.isAdjacent(j, i)) {
                    noIncoming = false;
                    break;
                }
            }
            if (noIncoming) {
                RecursiveDFSTopo(g, visited, i, dfsPostOrder);
            }
        }
    }
    // build list in reverse post-order
    while (!dfsPostOrder.empty()) {
        topo.append(dfsPostOrder.peek());
        dfsPostOrder.pop();
    }
    return topo;
}


int DenseGraph::maxConnection() {
    auto temp = numNodes-1;
    int ctr =0;
    int max=0;

    while(temp >= 0) {

        for (int i = 0; i < numNodes; i++) {
            if (isEdge(temp, i))
                ctr++;
        }
        if(ctr>max)
            max=ctr;

        ctr=0;  //reset counter
        temp--;

    }
    return max;
}
