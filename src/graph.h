#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include "graphNode.h"
#include "filereader.h"

using namespace std;

typedef vector<vector<int>> V2D; 

class Graph
{
public:
    Graph(const string &airportDataSet, const string &routesDataSet);
    ~Graph();
    // void addEdge(Airport* src, Airport* dest);
    // void dijkstra(int graph[x][y]);

    //    void addEdge(int v, int w);
    //    vector<Node *> dfs(Node *node);

    //adj matrix for all airports
    V2D graph;

    //string "airportID" is KEY
    //index in adj matrix is VALUE
    unordered_map<string, int> airport_idx;

};