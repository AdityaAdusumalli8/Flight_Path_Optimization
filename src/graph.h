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

    bool BFS(string src, string dest);
    // void dijkstra(int graph[x][y]);

    //adj matrix for all airports
    V2D graph;

    //string "airportID" is KEY
    //index in adj matrix is VALUE
    unordered_map<string, int> airport_idx;

};