//
// Created by eduardo on 14.10.21.
//

#ifndef BASICGRAPH_VERTEX_H
#define BASICGRAPH_VERTEX_H

#include <vector>
#include <initializer_list>
#include <climits>
#include <string>

enum class Color { white, gray, black };

using namespace std;

class Vertex 
{
public:
  
	Vertex(const string& label);
  Vertex(const Vertex& vertex);
  ~Vertex();

  void add(initializer_list<Vertex*> vertexes);

  int getDistance() const;

	int getStartTime() const;
	int getEndTime() const;		
//    friend ostream& operator<<(ostream& out, const Vertex& obj);

private:
	static const int UNDEFINED_TIME = -1;

  vector<Vertex*> adjacent_list;
  string label;
  Color color;
  int distance;
  int start_time;
	int end_time;
  Vertex* parent;

  friend class Graph;
};

//ostream& operator<<(ostream& out, const Vertex& obj)
//{
//    out << obj.label;
//    return out;
//}

#endif //BASICGRAPH_VERTEX_H
