//
// Created by eduardo on 10.10.21.
//

#ifndef BREATHFIRST_BREADTHFIRST_H
#define BREATHFIRST_BREADTHFIRST_H

#include "Graph.h"
#include "GraphNode.h"
#include "NodeToParentMap.h"

using namespace std;

class BreadthFirst {
public:
    BreadthFirst();

    virtual ~BreadthFirst() = 0;

    bool search(const Graph& graph, const GraphNode& start, const GraphNode& goal, const NodeToParentMap& outMap) const;
};


#endif //BREATHFIRST_BREADTHFIRST_H
