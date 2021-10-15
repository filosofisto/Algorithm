//
// Created by eduardo on 22.04.20.
//
#include "gtest/gtest.h"
#include "Graph.h"

TEST(GRAPH, Found)
{
    // start --- b --- d --- goal
    //   \                   /
    //    \                 /
    //     c ---------------

    Vertex* start = new Vertex();
    Vertex* b = new Vertex();
    Vertex* c = new Vertex();
    Vertex* d = new Vertex();
    Vertex* goal = new Vertex();

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

    EXPECT_TRUE(reachable);
}

TEST(GRAPH, Distance)
{
    // start --- b --- d --- goal
    //   \                   /
    //    \                 /
    //     c ---------------

    Vertex* start = new Vertex();
    Vertex* b = new Vertex();
    Vertex* c = new Vertex();
    Vertex* d = new Vertex();
    Vertex* goal = new Vertex();

    start->add({b, c});
    b->add({d});
    c->add({goal});
    d->add({goal});

    Graph* graph = new Graph();

    graph->add({start, b, c, d, goal});

    graph->breadthFirstSearch(start);

    EXPECT_EQ(b->getDistance(), 1);
    EXPECT_EQ(d->getDistance(), 2);
    EXPECT_EQ(c->getDistance(), 1);
    EXPECT_EQ(goal->getDistance(), 2);
}

TEST(GRAPH, NotFound)
{
    // start --- b  x  c --- goal
    Vertex* start = new Vertex();
    Vertex* b = new Vertex();
    Vertex* c = new Vertex();
    Vertex* goal = new Vertex();

    start->add({b});

    c->add({goal});

    Graph* graph = new Graph();

    graph->add({start, b, c, goal});

    graph->breadthFirstSearch(start);

    bool reachable = graph->reachableFrom(start, goal);

    delete graph;
    delete start;
    delete b;
    delete c;
    delete goal;

    EXPECT_FALSE(reachable);
}
