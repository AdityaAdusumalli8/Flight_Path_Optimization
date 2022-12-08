#include "filereader.h"
#include "graph.h"
#include <iostream>
using namespace std;

int main()
{
    Graph g = Graph("../src/airport.csv", "../src/routes.csv");

    bool t = g.BFS("AER", "NBC");
    cout<< t << endl;

    cout<< g.graph[3387][888] << endl;
    cout<< g.graph[890][888] << endl;

    // for(unsigned i=0; i<g.graph.size(); i++){
    //     for(unsigned j=0; j<g.graph[i].size(); j++){
    //         cout<< g.graph[i][j] << ",";
    //     }
    //     cout<< "" << endl;
    // }

    // FileData filedata = FileData();
    // filedata.readAirports("../src/airport.csv");
    // filedata.readRoutes("../src/routes.csv");
    
    //check contents of routes data
    // for (unsigned i = 0; i < filedata.routes.size(); i++){
    //     cout << filedata.routes[i]->_dist << endl;
    // }
    
    // //check contents of airport data
    // for (auto const& vals: filedata.airports) {
    //     cout << vals.first << endl;
    // }

    // //check size of filedata
    // cout << filedata.routes.size() << endl;
    // cout << filedata.airports.size() << endl;


    // SMALL SAMPLE

    // FileData filedata = FileData();
    // filedata.readAirports("../src/airport.csv");
    // filedata.readRoutes("../src/small_sample.csv");
    
    // //check contents of filedata
    // for (unsigned i = 0; i < filedata.routes.size(); i++){
    //     cout << filedata.routes[i]->_dist << endl;
    // }
    
    // check contents of filedata
    // for (auto const& vals: filedata.airports) {
    //     cout << vals.first << endl;
    // }

    // //check size of filedata
    // cout << filedata.routes.size() << endl;
    // cout << filedata.airports.size() << endl;
    
    return 0;
} 