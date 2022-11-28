#pragma once
#include "routes.h"
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class FileData
{
    public:
        FileData();
        void readAirports(const string &airportFile);
        void readRoutes(const string &routeFile);

        // need to get airport based on the 3-letter ID
        unordered_map<string, Airport *> airports;
        vector<Route *> routes;
};
