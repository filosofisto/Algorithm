//
// Created by eduardo on 22.04.20.
//
#include <iostream>
#include "gtest/gtest.h"
#include "Graph.h"

using namespace std;

TEST(GRAPH, Found)
{
    // start --- b --- d --- goal
    //   \                   /
    //    \                 /
    //     c ---------------

    /*Vertex* start = new Vertex("start");
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

    bool reachable = graph->reachableFrom(start, goal);

    delete graph;
    delete start;
    delete b;
    delete c;
    delete goal;

    EXPECT_TRUE(reachable);*/
}

