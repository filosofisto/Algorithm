//
// Created by eduardo on 15.10.21.
//
#include <iostream>
#include "Vertex.h"
#include "Graph.h"

int main()
{
    // start --- b --- d --- goal
    //   \                   /
    //    \                 /
    //     c ---------------

    Vertex* start = new Vertex("start");
    Vertex* b = new Vertex("b");
    Vertex* c = new Vertex("c");
    Vertex* d = new Vertex("d");
    Vertex* goal = new Vertex("goal");

    start->add({b, c});
    b->add({d});
    c->add({goal});
    d->add({goal});

    Graph* graph = new Graph();

    graph->add({start, b, c, d, goal});

    graph->breadthFirstSearch(start);

    graph->printPath(cout, start, goal);
}
