/*
 * Graph.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: blopez20
 */

#include "Graph.h"


void Graph::DFSR(int v, string& s)
{
    //set the city as visited
	vertices[v]->setVisited(true);

    s += vertices[v]->getName();

	for(int i = 0; i < vertices[v]->getEdges().size(); i++)
    {
		Vertex* dest = vertices[v]->getEdges()[i].getDestination();

		if(!dest->getVisited())
        {
            s += " »» ";
			DFSR(dest , s);
		}
	}
}

void Graph::DFSR(Vertex* dest, string& s)
{
    //set city as visited
	dest->setVisited(true);

    s += dest->getName();

	Vertex* destination;

	for(int i = 0; i < dest->getEdges().size(); i++)
    {
		destination = dest->getEdges()[i].getDestination();
		if(!destination->getVisited())
        {
            s += " »» ";
			DFSR(destination, s);
		}
	}
}


string Graph::Depth_First_Search( int v )
{
    string output = "";
    DFSR(v, output);

    resetFlags();
    return output;
}
string Graph::Depth_First_Search( Vertex *dest )
{
    string output = "";
    DFSR(dest, output);

    resetFlags();
    return output;
}


void Graph::insert(Vertex *v)
{
    vertices.push_back(v);
}

void Graph::printGraph()
{
    for (int i = 0; i < vertices.size(); i++)
        vertices[i]->printEdges();
}

vector<Vertex*> Graph::getVertexes()
{
    return vertices;
}

void Graph::resetFlags()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->setVisited(false);
    }
}




