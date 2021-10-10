//
// Created by eduardo on 10.10.21.
//

#ifndef BREATHFIRST_GRAPHNODE_H
#define BREATHFIRST_GRAPHNODE_H

#include <vector>

using namespace std;

class GraphNode {
public:
    GraphNode();
    ~GraphNode();

    void addGraphNode(const GraphNode& graphNode);

private:
    vector<GraphNode*> adjacent;
};


#endif //BREATHFIRST_GRAPHNODE_H
