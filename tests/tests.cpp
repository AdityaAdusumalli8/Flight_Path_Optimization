#include "graph.h"

TEST_CASE("TEST_BFS") {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    SECTION("BFS") {
        g.BFS(2);
        REQUIRE(g.getVisited(2) == true);
    }

    SECTION("DFS") {
        g.dfs(2);
        REQUIRE(g.getVisited(2) == true);
    }
}