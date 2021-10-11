//
// Created by eduardo on 10.10.21.
//

#include "GraphNode.h"

GraphNode::GraphNode()
{

}

GraphNode::~GraphNode()
{
    adjacent_list.clear();
}

void GraphNode::addGraphNode(GraphNode *graphNode)
{
    adjacent_list.push_back(graphNode);
}

vector<GraphNode *> GraphNode::adjacentList() const
{
    return adjacent_list;
}

