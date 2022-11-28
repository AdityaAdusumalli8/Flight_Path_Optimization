#pragma once
#include "airport.h"
#include "routes.h"
#include <vector>

class Node
{
public:
    Node(Route *route);
    ~Node();

    Airport *_airport;
    vector<Route *> edges;
};