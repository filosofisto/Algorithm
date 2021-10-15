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

class Vertex {
public:
    Vertex(const string& label);
    Vertex(const Vertex& vertex);
    ~Vertex();

    void add(initializer_list<Vertex*> vertexes);

    int getDistance() const;

//    friend ostream& operator<<(ostream& out, const Vertex& obj);

private:
    vector<Vertex*> adjacent_list;
    string label;
    Color color;
    int distance;
    Vertex* parent;

    friend class Graph;
};

//ostream& operator<<(ostream& out, const Vertex& obj)
//{
//    out << obj.label;
//    return out;
//}

#endif //BASICGRAPH_VERTEX_H
