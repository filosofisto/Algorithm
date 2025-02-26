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
		start->parent = nullptr;

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

void Graph::depthFirstSearch(Vertex* start)
{
	for (auto* vertex : vertexes) {
		vertex->color = Color::white;
		vertex->parent = nullptr;
	}

	int *time;
	*time = 0;

	for (auto* vertex : vertexes) {
		if (vertex->color == Color::white) {
			depthFirstSearchVisit(vertex, time);
		}
	}
}

void Graph::depthFirstSearchVisit(Vertex* vertex, int *time)
{
	*time += 1;
	vertex->start_time = *time;
	vertex->color = Color::gray;

	for (auto* v : vertex->adjacent_list) {
		if (v->color == Color::white) {
			v->parent = vertex;
			depthFirstSearchVisit(v, time);
		}
	}

	vertex->color = Color::black;
	*time += 1;
	vertex->end_time = *time;
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

