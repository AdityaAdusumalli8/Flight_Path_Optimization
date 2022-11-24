#pragma once
#include <string>
#include <vector>

using namespace std;

class FileData {
    readAirports(const string& airportFile);
    readRoutes(const string& routeFile);

    vector<Airport*> airports;
    vector<Route*> routes;
}
