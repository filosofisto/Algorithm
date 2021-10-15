//
// Created by eduardo on 14.10.21.
//

#include "Vertex.h"

Vertex::Vertex(const string& label):
    label(label),
    color(Color::white),
    distance(INT_MAX),
    parent(nullptr)
{

}

Vertex::Vertex(const Vertex &vertex)
{
    label = vertex.label;
    adjacent_list = vertex.adjacent_list; // copy vector
    color = vertex.color;
    parent = vertex.parent;
}

Vertex::~Vertex()
{
    adjacent_list.clear();
}

void Vertex::add(initializer_list<Vertex *> vertexes)
{
    for (auto vertex: vertexes) {
        adjacent_list.push_back(vertex);
    }
}

int Vertex::getDistance() const {
    return distance;
}




