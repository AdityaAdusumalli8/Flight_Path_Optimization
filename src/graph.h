#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <list> 
#include "filereader.h"

using namespace std;

typedef vector<vector<int>> V2D; 

class Graph
{
public:
    Graph(const string &airportDataSet, const string &routesDataSet);
    ~Graph();

    bool BFS(string src, string dest);

    void printPath(int currentVertex, vector<int> parents);
    int dijkstra(string src, string dest);

    int sumList(V2D graph, int row);
    vector<string> eulerian(int n);

    //adj matrix for all airports
    V2D graph;

    //string "airportID" is KEY
    //index in adj matrix is VALUE
    unordered_map<string, int> airport_idx;
    //reversed to get id from index
    unordered_map<int, string> idx_airport;
};