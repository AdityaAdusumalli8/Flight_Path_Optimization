#include "filereader.h"
#include "filereader.cpp"
#include <iostream>
using namespace std;

int main()
{
    FileData filedata = FileData();
    filedata.readRoutes("routes.csv");
    filedata.readAirports("airport.csv");

    for(int i=0; i<filedata.routes.size(); i++){
        cout<< filedata.routes[i]->_dist << endl;
    }
    for(auto const& vals: filedata.airports) {
        cout<< vals.first << endl;
    }
    return 0;
} 