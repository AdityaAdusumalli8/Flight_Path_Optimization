#include "../src/graph.h"
#include "../src/airport.h"
#include "../src/filereader.h"
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>

// TEST_CASE("TEST_BFS") {
//     Graph g(4);
//     g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 2);
//     g.addEdge(2, 0);
//     g.addEdge(2, 3);
//     g.addEdge(3, 3);

//     SECTION("BFS") {
//         g.BFS(2);
//         REQUIRE(g.getVisited(2) == true);
//     }

//     SECTION("DFS") {
//         g.dfs(2);
//         REQUIRE(g.getVisited(2) == true);
//     }
// }


TEST_CASE("Check Aiport Class","[weight=1]"){
    FileData filedata = FileData();
    filedata.readAirports("../src/airport.csv");
    string id = filedata.airports["GKA"]->getAirportID();
    REQUIRE(id == "GKA");
}

TEST_CASE("Check Route Class","[weight=1]"){
    FileData filedata = FileData();
    filedata.readAirports("../src/airport.csv");
    filedata.readRoutes("../src/routes.csv");
    REQUIRE(filedata.routes[6]->_srcAirport->getAirportID() == "DME" );
    REQUIRE(filedata.routes[6]->_destAirport->getAirportID() == "NBC" );
}

TEST_CASE("Check Distance Function ","[weight=1]"){
    Airport* SFO = new Airport("SFO", 37.615223, -122.389977);
    Airport* OHR = new Airport("OHR", 41.9803, -87.9090);
    Route* testRoute = new Route(SFO, OHR);
    auto distSquared = testRoute->calculateDist(SFO, OHR);

    REQUIRE(int(distSquared) == int(1207.9916720905));
}

TEST_CASE("TEST_CSV_Parse_Small") {
    FileData filedata = FileData();
    filedata.readAirports("../src/airport.csv");
    filedata.readRoutes("../src/routes_small.csv");
    
    REQUIRE(filedata.routes.size() == 6);
}

TEST_CASE("TEST_CSV_Parse_Big") {
    FileData filedata = FileData();
    filedata.readAirports("../src/airport.csv");
    filedata.readRoutes("../src/routes.csv");
    
    REQUIRE(filedata.routes.size() == 66607);
    REQUIRE(filedata.airports.size() == 6055);
}

TEST_CASE("Check BFS Easy") {
    Graph g = Graph("../src/airport.csv", "../src/routes.csv");
    bool t = g.BFS("LED", "KZN");

    REQUIRE(t == true);
}

TEST_CASE("Check BFS Hard") {
    Graph g = Graph("../src/airport.csv", "../src/routes.csv");
    bool t = g.BFS("AER", "NBC");
    
    REQUIRE(t == true);
}