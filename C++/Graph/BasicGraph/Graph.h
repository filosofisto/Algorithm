//
// Created by eduardo on 14.10.21.
//

#ifndef BASICGRAPH_GRAPH_H
#define BASICGRAPH_GRAPH_H

#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <initializer_list>
#include <iostream>

#include "Vertex.h"

using namespace std;

class Graph {
public:
    Graph();
    Graph(const Graph& graph);
    ~Graph();

    void add(initializer_list<Vertex*> vertexes);

    void breadthFirstSearch(Vertex* start);

    bool reachableFrom(Vertex* start, Vertex* goal);

    void printPath(ostream& out, Vertex* v1, Vertex* v2);

private:
    void resetForBreadthFirstSearch();
    vector<Vertex*> vertexes;
};

#endif //BASICGRAPH_GRAPH_H
