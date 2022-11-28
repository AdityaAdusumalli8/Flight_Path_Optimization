#pragma once
#include <vector>
#include <string>

using namespace std;

class Graph
{
public:
    Graph(const string &airportDataSet, const string &routesDataSet);
    ~Graph();

     vector<Node *> dfs(Node *node);



private:
    // map<string, bool> visited;
};