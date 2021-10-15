//
// Created by eduardo on 14.10.21.
//

#ifndef BASICGRAPH_VERTEX_H
#define BASICGRAPH_VERTEX_H

#include <vector>
#include <initializer_list>
#include <climits>

enum class Color { white, gray, black };

using namespace std;

class Vertex {
public:
    Vertex();
    Vertex(const Vertex& vertex);
    ~Vertex();

    void add(initializer_list<Vertex*> vertexes);

    int getDistance() const;
private:
    vector<Vertex*> adjacent_list;
    Color color;
    int distance;
    Vertex* parent;

    friend class Graph;
};


#endif //BASICGRAPH_VERTEX_H
