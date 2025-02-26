//
// Created by eduardo on 14.10.21.
//

#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

class Vertex 
{
public:
  
	Vertex(const string& label);
	~Vertex();

  string getLabel() const;
	int  getDistance() const;
	void setDistance(int distance); 
	void addAdjacent(Vertex* adjacent, int weight);
	bool operator>(const Vertex& other) const;
	unordered_map<Vertex*, int> getAdjacents() const;

private:
  unordered_map<Vertex*, int> adjacent_list; // Adjacent vertices and edge weights
  string label;
  int distance;

  friend class Graph;
};

#endif //VERTEX_H
