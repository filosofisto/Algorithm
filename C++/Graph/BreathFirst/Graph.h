//
// Created by eduardo on 10.10.21.
//

#ifndef BREATHFIRST_GRAPH_H
#define BREATHFIRST_GRAPH_H

#include <vector>
#include "GraphNode.h"

class Graph {
public:
    Graph();
    ~Graph();

    void addGraphNode(const GraphNode& graphNode);

private:
    vector<GraphNode*> nodes;
};


#endif //BREATHFIRST_GRAPH_H
