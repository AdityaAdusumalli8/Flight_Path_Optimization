#include "graphNode.h"
#include <vector>

using namespace std;

Node::Node(Route *route)
{
    _airport = route->_srcAirport;
    edges.push_back(route);
}

Node::~Node()
{
}