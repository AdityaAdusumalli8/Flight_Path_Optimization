#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include "graphNode.h"

using namespace std;

class Graph
{
public:
    Graph(const string &airportDataSet, const string &routesDataSet);
    Graph();
    ~Graph();

   void addEdge(int v, int w);
   vector<Node *> dfs(Node *node);



private:
    list <int> *adj;
    int V;
    // map<string, bool> visited;
};