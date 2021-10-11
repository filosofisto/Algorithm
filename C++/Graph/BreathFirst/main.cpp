#include <iostream>
#include "GraphNode.h"
#include "Graph.h"

int main()
{
    std::cout << "Breadth First Search" << std::endl;

    // start --- b --- d --- goal
    //   \                   /
    //    \                 /
    //     c ---------------

    GraphNode* start = new GraphNode();
    GraphNode* b = new GraphNode();
    GraphNode* c = new GraphNode();
    GraphNode* d = new GraphNode();
    GraphNode* goal = new GraphNode();

    start->addGraphNode(b);
    start->addGraphNode(c);

    b->addGraphNode(d);

    c->addGraphNode(goal);

    d->addGraphNode(goal);

    Graph* graph = new Graph();

    graph->addGraphNode(start);
    graph->addGraphNode(b);
    graph->addGraphNode(c);
    graph->addGraphNode(d);
    graph->addGraphNode(goal);

    NodeToParentMap nodeToParentMap;

    if (graph->breadthFirstSearch(start, goal, nodeToParentMap)) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    delete start;
    delete b;
    delete c;
    delete goal;
    delete graph;

    return EXIT_SUCCESS;
}