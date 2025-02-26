#include "Vertex.h"

Vertex::Vertex(const string& label):
  label(label),
  distance(std::numeric_limits<int>::max())
{

}

Vertex::~Vertex()
{
    adjacent_list.clear();
}

int Vertex::getDistance() const {
    return distance;
}

void Vertex::setDistance(int distance) {
	this->distance = distance;
}

void Vertex::addAdjacent(Vertex* adjacent, int weight)
{
	adjacent_list[adjacent] = weight;
}

std::unordered_map<Vertex*, int> Vertex::getAdjacents() const
{
	return adjacent_list;
}

bool Vertex::operator>(const Vertex& other) const
{
	return distance > other.distance;
}

std::string Vertex::getLabel() const
{
	return label;
}
