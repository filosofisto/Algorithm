//
// Created by eduardo on 10.10.21.
//

#include "GraphNode.h"

GraphNode::GraphNode()
{

}

GraphNode::GraphNode(const GraphNode &graphNode)
{
    adjacent_list = graphNode.adjacent_list; // copy vector
}

GraphNode::~GraphNode()
{
    adjacent_list.clear();
}

void GraphNode::addGraphNodes(initializer_list<GraphNode*> graphNodes)
{
    for (auto graphNode: graphNodes) {
        adjacent_list.push_back(graphNode);
    }
}

vector<GraphNode *> GraphNode::getAdjacentList() const
{
    return adjacent_list;
}

