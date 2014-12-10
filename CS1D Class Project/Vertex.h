

#ifndef VERTEX_H_
#define VERTEX_H_

#include <iostream>
#include <vector>
#include <iomanip>
#include "Edge.h"
using namespace std;

/*********************************************************
 * Vertex Class
 * ------------------------------------------------------
 * Description: Contains the name of the vertex and a vector
 * of edges that this vertex is connected to. Each vertex
 * has a flag to see if has been visited
 *********************************************************/
class Vertex
{
public:

    //non default constructor
    Vertex(string name);

    //add an edge to this vertex
    void addEdge(Vertex *v, int dist);

    //print all the edges of the vertex
    void printEdges();

    string getName();

    vector<Edge> getEdges();
    void setVisited( bool b );

    bool getVisited();

private:
    string name;
    vector<Edge> edges;
    bool visited;

};



#endif /* VERTEX_H_ */
