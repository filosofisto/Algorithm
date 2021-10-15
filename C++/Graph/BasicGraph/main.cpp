//
// Created by eduardo on 15.10.21.
//
#include <iostream>
#include "Vertex.h"
#include "Graph.h"

// TODO: Replace this main by unit test
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
    Vertex* no_path = new Vertex("no_path");

    start->add({b, c});
    b->add({d});
    c->add({goal});
    d->add({goal});

    Graph* graph = new Graph();

    graph->add({start, b, c, d, goal, no_path});

    graph->breadthFirstSearch(start);

    graph->printPath(cout, start, goal);

    // No path existence
    graph->printPath(cout, start, no_path);

}
