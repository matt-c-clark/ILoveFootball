/*
 * Edge.h
 *
 *  Created on: Dec 9, 2014
 *      Author: blopez20
 */

#ifndef EDGE_H_
#define EDGE_H_

#include <iostream>
//declare to use in Edge class
class Vertex;

/*********************************************************
 * Edge Class
 * ------------------------------------------------------
 * Description: Edge class contains two vertex pointers:
 * one for the destination vertex and one for the origin vertex.
 * Edge class also contains the distance between the 2 vertexes.
 *********************************************************/
class Edge
{
public:

    //non default constructor
    Edge(Vertex *origin, Vertex *destination, int distance);

    //get the vertex that is the origin of the edge
    Vertex* getOrigin();

    //get the vertex that is the destination of the edge
    Vertex* getDestination();

    //get the distance between the 2 vertexes
    int getDistance();

private:
    Vertex* origin;         //the vertex that is the origin of the edge
    Vertex* destination;    //the vertex that is the destination of the edge
    int distance;           //the distance between the 2 vertexes
};



#endif /* EDGE_H_ */
