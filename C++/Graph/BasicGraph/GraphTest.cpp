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

    EXPECT_EQ(b->getDistance(), 1);
    EXPECT_EQ(d->getDistance(), 2);
    EXPECT_EQ(c->getDistance(), 1);
    EXPECT_EQ(goal->getDistance(), 2);
}

TEST(GRAPH, NotFound)
{
    // start --- b  x  c --- goal
    Vertex* start = new Vertex("start");
    Vertex* b = new Vertex("b");
    Vertex* c = new Vertex("c");
    Vertex* goal = new Vertex("goal");

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

TEST(GRAPH, printPath)
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

TEST(GRAPH, DepthFirstSearch)
{
  // u - v  w
  // | / | /|
  // x - y  z
  //

  Vertex* u = new Vertex("u");
  Vertex* v = new Vertex("v");
  Vertex* w = new Vertex("w");
  Vertex* x = new Vertex("x");
  Vertex* y = new Vertex("y");
  Vertex* z = new Vertex("z");

  u->add({v, x});
  v->add({y});
  x->add({v});
	y->add({x});
  w->add({y,z});
	z->add({z});

  Graph* graph = new Graph();
  graph->add({u, v, w, x, y, z});
	
	graph->depthFirstSearch(u);
  
	
	EXPECT_EQ(1, u->getStartTime());
	EXPECT_EQ(8, u->getEndTime());

 	EXPECT_EQ(2, v->getStartTime());
	EXPECT_EQ(7, v->getEndTime());

	EXPECT_EQ(9,  w->getStartTime());
	EXPECT_EQ(12, w->getEndTime());

	EXPECT_EQ(4, x->getStartTime());
	EXPECT_EQ(5, x->getEndTime());

	EXPECT_EQ(3, y->getStartTime());
	EXPECT_EQ(6, y->getEndTime());

	EXPECT_EQ(10, z->getStartTime());
	EXPECT_EQ(11, z->getEndTime());

	delete graph;
  delete u;
  delete v;
  delete w;
  delete x;
	delete y;
	delete z;
}


