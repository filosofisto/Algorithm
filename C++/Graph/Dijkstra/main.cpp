//
// Created by eduardo on 15.10.21.
//
#include <iostream>
#include "Vertex.h"
#include "Graph.h"

int main()
{
	// Create vertices
  Vertex* v1 = new Vertex("A");
  Vertex* v2 = new Vertex("B");
  Vertex* v3 = new Vertex("C");
  Vertex* v4 = new Vertex("D");

  // Create graph and add vertices
  Graph graph;
  graph.addVertex(v1);
  graph.addVertex(v2);
  graph.addVertex(v3);
  graph.addVertex(v4);

  // Add edges
  graph.addEdge(v1, v2, 1);
  graph.addEdge(v1, v3, 4);
  graph.addEdge(v2, v3, 2);
  graph.addEdge(v2, v4, 6);
  graph.addEdge(v3, v4, 3);

  // Run Dijkstra's algorithm from source vertex v1
  graph.dijkstra(v1);

  // Print distances
  for (auto& vertex : graph.getVertices()) {
  	std::cout << "Distance from A to " << vertex->getLabel() << " is " << vertex->getDistance() << std::endl;
  }

  // Clean up
  delete v1;
  delete v2;
  delete v3;
  delete v4;

	return EXIT_SUCCESS;
}
