#include "Vertex.h"

//non default constructor
Vertex::Vertex(string name)
{
    this->name = name;
    visited = false;
}

//add an edge to this vertex
void Vertex::addEdge(Vertex *v, int dist)
{
    //add the new edge to the edge list
    edges.push_back(Edge(this, v, dist));
}

//print all the edges of the vertex
void Vertex::printEdges()
{
    printf("%-25s%-25s%-5s\n", name.c_str(), "Connected", "Distance");
    cout << setw(58) << setfill('-') << "" << endl;
    for (int i = 0; i < edges.size(); i++)
    {
        printf("%-25s%-25s%-5d\n", "",
               edges[i].getDestination()->getName().c_str(),
               edges[i].getDistance());
    }
    cout << endl;
}

string Vertex::getName()
{
    return name;
}

vector<Edge> Vertex::getEdges()
{
    return edges;
}

void Vertex::setVisited( bool b )
{
    visited = b;
}

bool Vertex::getVisited()
{
    return visited;
}
