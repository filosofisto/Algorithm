//
// Created by eduardo on 10.10.21.
//

#ifndef BREATHFIRST_GRAPHNODE_H
#define BREATHFIRST_GRAPHNODE_H

#include <vector>
#include <initializer_list>

using namespace std;

class GraphNode {
public:
    GraphNode();
    GraphNode(const GraphNode& graphNode);
    ~GraphNode();

    void addGraphNodes(initializer_list<GraphNode *> graphNodes);

    vector<GraphNode*> getAdjacentList() const;

private:
    vector<GraphNode*> adjacent_list;
};


#endif //BREATHFIRST_GRAPHNODE_H
