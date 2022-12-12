#include "../src/graph.h"
#include "../src/airport.h"
#include "../src/filereader.h"
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>

TEST_CASE("Check Aiport Class","[weight=1]"){
    FileData filedata = FileData();
    filedata.readAirports("../tests/airport.csv");
    string id = filedata.airports["GKA"]->getAirportID();
    REQUIRE(id == "GKA");
}

TEST_CASE("Check Route Class","[weight=1]"){
    FileData filedata = FileData();
    filedata.readAirports("../tests/airport.csv");
    filedata.readRoutes("../tests/routes.csv");
    REQUIRE(filedata.routes[6]->_srcAirport->getAirportID() == "DME" );
    REQUIRE(filedata.routes[6]->_destAirport->getAirportID() == "NBC" );
}

TEST_CASE("Check Distance Function ","[weight=1]"){
    Airport* SFO = new Airport("SFO", 37.615223, -122.389977);
    Airport* OHR = new Airport("OHR", 41.9803, -87.9090);
    Route* testRoute = new Route(SFO, OHR);
    auto distSquared = testRoute->calculateDist(SFO, OHR);

    REQUIRE(int(distSquared) == 3833);
}

TEST_CASE("TEST_CSV_Parse_Small") {
    FileData filedata = FileData();
    filedata.readAirports("../tests/airport.csv");
    filedata.readRoutes("../tests/routes_small.csv");
    
    REQUIRE(filedata.routes.size() == 20);
}

TEST_CASE("TEST_CSV_Parse_Big") {
    FileData filedata = FileData();
    filedata.readAirports("../tests/airport.csv");
    filedata.readRoutes("../tests/routes.csv");
    
    REQUIRE(filedata.routes.size() == 66607);
    REQUIRE(filedata.airports.size() == 6055);
}

TEST_CASE("Check BFS Easy") {
    Graph g = Graph("../tests/airport.csv", "../tests/routes.csv");
    bool t = g.BFS("LED", "KZN");

    REQUIRE(t == true);
}

TEST_CASE("Check BFS Medium") {
    Graph g = Graph("../tests/airport.csv", "../tests/routes.csv");
    bool t = g.BFS("AER", "NBC");
    
    REQUIRE(t == true);
}

TEST_CASE("Check BFS Hard") {
    Graph g = Graph("../tests/airports_small.csv", "../tests/routes_small.csv");
    bool t = g.BFS("AER", "GYD");
    
    REQUIRE(t == false);
}

TEST_CASE("Check Dijkstras Easy") {
    Graph g = Graph("../tests/airports_small.csv", "../tests/routes_small.csv");
    int dist = g.dijkstra("GYD", "AER");
    
    REQUIRE(dist == -1);
}

TEST_CASE("Check Dijkstras Hard") {
    Graph g = Graph("../tests/airports_small.csv", "../tests/routes_small.csv");
    int dist = g.dijkstra("DME", "AER");
    
    REQUIRE(dist == 2674);
}


TEST_CASE("Check Eulerian Path Doesn't Exist") {
    Graph g = Graph("../tests/airports_small.csv", "../tests/routes_small.csv");
    vector<string> path = g.eulerian(g.graph.size());
    
    REQUIRE(path.size() == 0);
}

TEST_CASE("Check Eulerian Path Exists") {
    Graph g = Graph("../tests/airports_eulerian.csv", "../tests/routes_eulerian.csv");
    vector<string> path = g.eulerian(g.graph.size());
    vector<string> check;
    check.push_back("KZN");
    check.push_back("AER");
    check.push_back("ASF");
    check.push_back("KZN");
    check.push_back("CEK");
    check.push_back("DME");
    check.push_back("KZN");
    check.push_back("EGO");
    check.push_back("KGD");
    
    REQUIRE(path == check);
}