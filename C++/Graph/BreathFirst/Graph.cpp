//
// Created by eduardo on 10.10.21.
//

#include "Graph.h"

Graph::Graph()
{

}

Graph::Graph(const Graph &graph)
{
    nodes = graph.nodes; // copy vector
}

Graph::~Graph()
{
    nodes.clear();
}

void Graph::addGraphNodes(initializer_list<GraphNode*> graphNodes)
{
    for (auto graphNode: graphNodes) {
        nodes.push_back(graphNode);
    }
}

bool Graph::breadthFirstSearch(const GraphNode *start, const GraphNode *goal, NodeToParentMap &outMap) const
{
    bool pathFound = false;

    queue<const GraphNode*> q;
    q.emplace(start);

    while (!q.empty()) {
        const GraphNode* current = q.front();
        q.pop();

        if (current == goal) {
            pathFound = true;
            break;
        }

        for (const GraphNode* node: current->getAdjacentList()) {
            const GraphNode* parent = outMap[node];
            if (parent == nullptr && node != start) {
                outMap[node] = current;
                q.emplace(node);
            }
        }
    }

    return pathFound;
}
