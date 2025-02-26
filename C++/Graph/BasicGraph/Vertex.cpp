//
// Created by eduardo on 14.10.21.
//

#include "Vertex.h"

Vertex::Vertex(const string& label):
  label(label),
  color(Color::white),
  distance(INT_MAX),
  parent(nullptr),
	start_time(UNDEFINED_TIME),
	end_time(UNDEFINED_TIME)
{

}

Vertex::Vertex(const Vertex &vertex)
{
  label = vertex.label;
  adjacent_list = vertex.adjacent_list; // copy vector
  color = vertex.color;
  parent = vertex.parent;
	start_time = vertex.start_time;
	end_time = vertex.end_time;
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

int Vertex::getStartTime() const
{
	return start_time;
}

int Vertex::getEndTime() const
{
	return end_time;
}	

