#include "Graph.h"

Graph::Graph()
{

}

Graph::~Graph()
{
    vertices.clear();
}

void Graph::addVertex(Vertex * vertex)
{
	vertices[vertex->label] = vertex;
}

void Graph::addEdge(Vertex *from, Vertex *to, int weight)
{
	from->addAdjacent(to, weight);
}

void Graph::dijkstra(Vertex *source)
{
	// Priority queue to store vertices based on their distance
	std::priority_queue<Vertex*, std::vector<Vertex*>, std::greater<>> pq;

	// Initialize the source vertex
	source->setDistance(0);
	pq.push(source);

	while (!pq.empty()) {
		Vertex *current = pq.top();
		pq.pop();

		// Visit ajacent list of the current vertex
		for (auto& neighbor : current->getAdjacents()) {
			Vertex *adjacent = neighbor.first;
			int weight = neighbor.second;

			// Relax the edge
			if (current->getDistance() + weight < adjacent->getDistance()) {
				adjacent->setDistance(current->getDistance() + weight);
				pq.push(adjacent);
			}
		}
	}
}

vector<Vertex*> Graph::getVertices() const
{
	std::unordered_set<Vertex*> uniqueVertices; // To avoid duplicates
  vector<Vertex*> result;

  // Iterate through all vertices in the graph
  for (auto& pair : vertices) {
	  Vertex* vertex = pair.second;

    // Add the current vertex to the set
    uniqueVertices.insert(vertex);

    // Iterate through its neighbors and add them to the set
    for (auto& neighbor : vertex->getAdjacents()) {
	    uniqueVertices.insert(neighbor.first);
    }
  }

  // Convert the set to a vector
  for (auto vertex : uniqueVertices) {
  	result.push_back(vertex);
  }

  return result;
}

