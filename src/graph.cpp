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
        graph[dest_idx][src_idx] = f.routes[i]->_dist;
    }
}


Graph::~Graph()
{
    //dtor
}

//checks whether a path exists from the scr to dest airport
bool Graph::BFS(string src, string dest){
    //if any invalid airports return false
    if(airport_idx.find(src)==airport_idx.end() || airport_idx.find(dest)==airport_idx.end()){
        return false;
    }

    int start = airport_idx[src];
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    //prep for first iteration
    q.push(start);
    visited[start] = true;
    int cur;

    //if the queue is empty, we have visited all the airports
    while(!q.empty()){
        //we look at the top element from the queue each iteration
        cur = q.front();
        q.pop();
        //add all neighboring, unvisited airports to queue
        for(unsigned i = 0; i < graph[cur].size(); i++){
            if(graph[cur][i] != 0 && (!visited[i])){
                q.push(i);
                visited[i] = true;
                //if we have reached the destination airport return true
                if(int(i)==airport_idx[dest]) return true;
            }
        }
    }
    return false;
}


void Graph::printPath(int currentVertex, vector<int> parents){
 
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
    vector path(graph.size(), false);

    //each airport will have an int which represents its parent index, or the previous
    //airport in the route
    vector<int> parents(graph.size());
    parents[airport_idx[src]] = -1;

    //the distance from the source airport to itself is 0
    dist[airport_idx[src]] = 0;

    //find the shortest distance of every node
    for (unsigned i = 0; i < graph.size()-1; i++) {
        //process each node one at a time so pick the min
        //distance airport from whichever airports havent
        //been visited yet
        int nearestNode = -1; 
        int shortestDist = INT_MAX;
        for (unsigned v = 0; v < graph.size(); v++) {
            if (!path[v] && dist[v]< shortestDist) {
                nearestNode = v;
                shortestDist = dist[v];
            }
        }

        if(nearestNode==-1) continue;
        //change the nearest airport to processed
        path[nearestNode] = true;
 
        //update the shortest distances for each of the adj nodes to nearestNode
        for (unsigned v = 0; v < graph.size(); v++) {
            int edge_dist = graph[nearestNode][v];
            //we do shortest dist + edge dist since nodes x->z may have dist 9
            //however if x->y has shortest dist 2 and edge dist of y->z is 5, 7 < 9 so 
            //the new shortest dist from x->z would be 7
            if (edge_dist > 0 && ((shortestDist + edge_dist)<dist[v])) {
                parents[v] = nearestNode;
                dist[v] = shortestDist + edge_dist;
            }
        }
    }

    //if the destination airport was never reached return -1
    if(dist[airport_idx[dest]]==INT_MAX){
        return -1;
    } 
    else{ //if it was print the path
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
 
    //find number of edges for each node
    for (int i = 0; i < n; i++){
        numAdj.push_back(sumList(mtrx, i));
    }
    
    //count how many nodes have odd number of edges
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

    //if there are more than 2 nodes with odd number of 
    //edges, then a eulerian path cant be made
    if (oddNum > 2){
        vector<string> res;
        return res;
    }

    //while the current node has at least one neighbor or the stack is not empty 
    //discover the neighboring node and then the current node by backtracking
    int current = start;
    while (sumList(mtrx,current)!= 0 || !s.empty())
    {
        //If the current node has no neighbors then add it to the 
        //path and pop stack, set current to popped vertex.
        if (sumList(mtrx,current) == 0)
        {
            path.push_back(idx_airport[current]);
            current = s.top();
            s.pop();
        }  
        //if there are neighbors
        else
        {
            int i = 0;
            while(i<n){
                //add the current node to stack, 
                //remove the edge between the current node and neighbor node 
                //set current to the neighbor node.
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

    //the node we end on won't be pushed in the loop so add it here
    path.push_back(idx_airport[current]);
    return path;
}
 




