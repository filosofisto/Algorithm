#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include "Vertex.h"

using namespace std;

class Graph 
{
public:
	
	Graph();
  ~Graph();

	void addVertex(Vertex *vertex);
	void addEdge(Vertex *from, Vertex *to, int weight);
	vector<Vertex*> getVertices() const;

	void dijkstra(Vertex *source);
private:

	std::unordered_map<string, Vertex*> vertices;  
};

#endif //GRAPH_H
