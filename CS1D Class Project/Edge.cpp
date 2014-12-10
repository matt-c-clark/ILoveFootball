#include "Edge.h"

//non default constructor
Edge::Edge(Vertex *origin, Vertex *destination, int distance)
{
    this->origin = origin;
    this->destination = destination;
    this->distance = distance;
}

//get the vertex that is the origin of the edge
Vertex* Edge::getOrigin()
{
    return origin;
}

//get the vertex that is the destination of the edge
Vertex* Edge::getDestination()
{
    return destination;
}

//get the distance between the 2 vertexes
int Edge::getDistance()
{
    return distance;
}
