/*
 * Graph.h
 *
 *  Created on: Dec 9, 2014
 *      Author: blopez20
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"


class Graph
{
public:
    Graph() {}
	void DFSR(int v, string& s);
	void DFSR(Vertex *dest, string& s);

    string Depth_First_Search( int v );
    string Depth_First_Search( Vertex *dest );

    void insert(Vertex *v);
    void printGraph();
    vector<Vertex*> getVertexes();
    void resetFlags();

private:
    vector<Vertex*> vertices;

};



#endif /* GRAPH_H_ */
