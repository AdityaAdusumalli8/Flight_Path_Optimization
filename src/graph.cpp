#include "graph.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

typedef vector<vector<int>> V2D; 

Graph::Graph(const string &airportDataSet, const string &routesDataSet) {
    FileData f = FileData();
    f.readAirports(airportDataSet);
    f.readRoutes(routesDataSet);
    int i = 0;
    vector<int> v;
    for (unordered_map<string,Airport*>::iterator iter = f.airports.begin(); iter != f.airports.end(); ++iter){
        string k = iter->first;
        airport_idx[k] = i;
        idx_airport[i] = k;
        v.push_back(0);
        i+=1;
    }
    for(int j=0; j<i; j++){
        graph.push_back(v);
    }

    for(unsigned i=0; i<f.routes.size(); i++){
        string srcID = f.routes[i]->_srcAirport->airport_ID;
        string destID = f.routes[i]->_destAirport->airport_ID;
        int src_idx = airport_idx[srcID];
        int dest_idx = airport_idx[destID];
        graph[src_idx][dest_idx] = f.routes[i]->_dist;
    }
}


Graph::~Graph()
{
    //dtor
}

//checks whether a path exists from the scr to dest airport
bool Graph::BFS(string src, string dest){
    if(airport_idx.find(src)==airport_idx.end() || airport_idx.find(dest)==airport_idx.end())
        return false;
        
    int start = airport_idx[src];
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);

    visited[start] = true;

    int vis;
    while(!q.empty()){
        vis = q.front();
        q.pop();
        for(unsigned i = 0; i < graph[vis].size(); i++){
            if(graph[vis][i] != 0 && (!visited[i])){
                q.push(i);
                visited[i] = true;
                if(int(i)==airport_idx[dest]) return true;
            }
        }
    }
    return false;
}


void Graph::printPath(int currentVertex, vector<int> parents){
 
    // Base case : Source node has
    // been processed
    if (currentVertex == -1) {
        return;
    }
    printPath(parents[currentVertex], parents);
    cout << idx_airport[currentVertex] << "->";
}


//returns shortest path between two airports
int Graph::dijkstra(string src, string dest){
    if(airport_idx.find(src)==airport_idx.end() || airport_idx.find(dest)==airport_idx.end())
        return -1;

    //holds the shortest dist from src to each airport
    vector dist(graph.size(), INT_MAX);

    //if vertex is in the curr shortest path its associated index 
    //is true in the path array
    vector added(graph.size(), false);

    vector<int> parents(graph.size());
    parents[airport_idx[src]] = -1;

    dist[airport_idx[src]] = 0;

    for (unsigned i = 0; i < graph.size()-1; i++) {
 
        int nearestNode = -1;
        int shortestDist = INT_MAX;
        for (unsigned v = 0; v < graph.size(); v++) {
            if (!added[v] && dist[v]<shortestDist) {
                nearestNode = v;
                shortestDist = dist[v];
            }
        }

        if(nearestNode==-1) continue;
        added[nearestNode] = true;
 
        for (unsigned v = 0; v < graph.size(); v++) {
            int edgeDistance = graph[nearestNode][v];
 
            if (edgeDistance > 0 && ((shortestDist + edgeDistance)<dist[v])) {
                parents[v] = nearestNode;
                dist[v] = shortestDist + edgeDistance;
            }
        }
    }

    if(dist[airport_idx[dest]]==INT_MAX){
        return -1;
    } 
    else{
        printPath(airport_idx[dest], parents);
        cout<<endl;
    }
    return dist[airport_idx[dest]];
}


//find number of edges given idx of vertex
int Graph::sumList(V2D mtrx, int row){
    int sum=0;
    for(unsigned i=0; i<mtrx.size(); i++){
        if(mtrx[row][i]!=0) sum+=1;
    }
    return sum;
}


vector<string> Graph::eulerian(int n)
{
    V2D mtrx = graph;
    vector<int> numAdj;
    vector<string> path;
    stack<int> s;
 
    for (int i = 0; i < n; i++){
        numAdj.push_back(sumList(mtrx, i));
    }
    
    int start, oddNum = 0;
    for (int i = n - 1; i >= 0; i--){
        switch(numAdj[i]%2){
            case(1):
                oddNum++;
                start = i;
            default:
                continue;
        }
    }

    if (oddNum > 2){
        vector<string> res;
        return res;
    }

    int current = start;
    while (sumList(mtrx,current)!= 0 || !s.empty())
    {

        if (sumList(mtrx,current) == 0)
        {
            path.push_back(idx_airport[current]);
            current = s.top();
            s.pop();
        }
        
        else
        {
            int i = 0;
            while(i<n){
                if (mtrx[current][i] > 0){
                    mtrx[i][current] = 0;
                    mtrx[current][i] = 0;
                    s.push(current);
                    current = i;
                    break;
                }
                i++;
            }
        }
    }

    path.push_back(idx_airport[current]);
    return path;
}
 




