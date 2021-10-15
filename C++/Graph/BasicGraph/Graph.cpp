//
// Created by eduardo on 14.10.21.
//

#include "Graph.h"

Graph::Graph()
{

}

Graph::Graph(const Graph &graph)
{
    vertexes = graph.vertexes; // copy vector
}

Graph::~Graph()
{
    vertexes.clear();
}

void Graph::add(initializer_list<Vertex *> vertexes)
{
    for (auto vertex: vertexes) {
        this->vertexes.push_back(vertex);
    }
}

void Graph::breadthFirstSearch(Vertex *start)
{
    resetForBreadthFirstSearch();

    start->color = Color::gray;
    start->distance = 0;

    queue<Vertex*> q;
    q.emplace(start);

    while (!q.empty()) {
        Vertex* current = q.front();
        q.pop();

        for (Vertex* vertex: current->adjacent_list) {
            if (vertex->color == Color::white) {
                vertex->color = Color::gray;
                vertex->distance = current->distance + 1;
                vertex->parent = current;

                q.emplace(vertex);
            }
        }

        current->color = Color::black;
    }

}

bool Graph::reachableFrom(Vertex *start, Vertex *goal)
{
    breadthFirstSearch(start);
    return goal->distance < INT_MAX;
}

void Graph::resetForBreadthFirstSearch()
{
    for (auto vertex: vertexes) {
        vertex->color = Color::white;
        vertex->distance = INT_MAX;
        vertex->parent = nullptr;
    }
}

void Graph::printPath(ostream& out, Vertex *v1, Vertex *v2)
{
    if (v1 == v2) {
        out << v1->label << endl;
    } else if (v2->parent == nullptr) {
        out << "no path exists" << endl;
    } else {
        printPath(out, v1, v2->parent);
        out << v2->label << endl;
    }
}

