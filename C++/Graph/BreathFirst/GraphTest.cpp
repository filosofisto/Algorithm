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

    GraphNode* start = new GraphNode();
    GraphNode* b = new GraphNode();
    GraphNode* c = new GraphNode();
    GraphNode* d = new GraphNode();
    GraphNode* goal = new GraphNode();

    start->addGraphNodes({b, c});
    b->addGraphNodes({d});
    c->addGraphNodes({goal});
    d->addGraphNodes({goal});

    Graph* graph = new Graph();

    graph->addGraphNodes({start, b, c, d, goal});

    NodeToParentMap nodeToParentMap;

    bool result = graph->breadthFirstSearch(start, goal, nodeToParentMap);

    delete graph;
    delete start;
    delete b;
    delete c;
    delete goal;

    EXPECT_TRUE(result);
}

TEST(GRAPH, NotFound)
{
    // start --- b  x  c --- goal
    GraphNode* start = new GraphNode();
    GraphNode* b = new GraphNode();
    GraphNode* c = new GraphNode();
    GraphNode* goal = new GraphNode();

    start->addGraphNodes({b});

    c->addGraphNodes({goal});

    Graph* graph = new Graph();

    graph->addGraphNodes({start, b, c, goal});

    NodeToParentMap nodeToParentMap;

    bool result = graph->breadthFirstSearch(start, goal, nodeToParentMap);

    delete graph;
    delete start;
    delete b;
    delete c;
    delete goal;
    delete graph;

    EXPECT_FALSE(result);
}

//TEST(STACK, Empty)
//{
//    auto stack = new Stack<int>();
//    EXPECT_TRUE(stack->empty());
//    stack->push(new int(1));
//    EXPECT_FALSE(stack->empty());
//}
//
//TEST(STACK, PushPop)
//{
//    auto stack = new Stack<int>();
//    EXPECT_TRUE(stack->empty());
//    stack->push(new int(1));
//    EXPECT_FALSE(stack->empty());
//    int value = *stack->pop();
//    EXPECT_TRUE(stack->empty());
//    EXPECT_EQ(1, value);
//}
//
//TEST(STACK, Peek)
//{
//    auto stack = new Stack<int>();
//    EXPECT_TRUE(stack->empty());
//    stack->push(new int(1));
//    EXPECT_FALSE(stack->empty());
//    int value = *stack->peek();
//    EXPECT_FALSE(stack->empty());
//    EXPECT_EQ(1, value);
//}