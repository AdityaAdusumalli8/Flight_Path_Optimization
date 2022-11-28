#pragma once
#include <vector>
#include <string>
#include "graphNode.h"

using namespace std;

class Graph
{
public:
    Graph(const string &airportDataSet, const string &routesDataSet);
    Graph();
    ~Graph();

    vector<Node *> dfs(Node *node);



private:
    // map<string, bool> visited;
};