#pragma once 
#include "airport.h"

using namespace std;

class Route{
    public:
        Route(Airport* src, Airport* dest);
        Route(const Route& other);
        ~Route();
        // bool operator==(const Route &other);
        double calculateDist(Airport* src, Airport* dest);

        Airport* _srcAirport;
        Airport* _destAirport;
        double _dist;  
};