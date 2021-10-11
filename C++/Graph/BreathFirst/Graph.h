//
// Created by eduardo on 10.10.21.
//

#ifndef BREATHFIRST_GRAPH_H
#define BREATHFIRST_GRAPH_H

#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include "GraphNode.h"

using namespace std;

using NodeToParentMap = unordered_map <const GraphNode*, const GraphNode*>;

class Graph {
public:
    Graph();
    ~Graph();

    void addGraphNode(GraphNode* graphNode);

    bool breadthFirstSearch(const GraphNode* start, const GraphNode* goal, NodeToParentMap& outMap) const;

private:
    vector<GraphNode*> nodes;
};


#endif //BREATHFIRST_GRAPH_H
