#include "graph.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits.h>

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
void Graph::dijkstra(string src, string dest){
    //holds the shortest dist from src to each airport
    vector dist(graph.size(), INT_MAX);

    //if vertex is in the curr shortest path its associated index 
    //is true in the path array
    vector added(graph.size(), false);

    vector<int> parents(graph.size());
    parents[airport_idx[src]] = -1;

    dist[airport_idx[src]] = 0;

    cout<<"start"<<endl;
    for (unsigned i = 0; i < graph.size()-1; i++) {
 
        // Pick the minimum distance vertex
        // from the set of vertices not yet
        // processed. nearestNode is
        // always equal to startNode in
        // first iteration.
        int nearestNode = -1;
        int shortestDist = INT_MAX;
        for (unsigned v = 0; v < graph.size(); v++) {
            if (!added[v] && dist[v]<shortestDist) {
                nearestNode = v;
                shortestDist = dist[v];
            }
        }

        if(nearestNode==-1) continue;
        // Mark the picked vertex as
        // processed
        added[nearestNode] = true;
 
        // Update dist value of the
        // adjacent vertices of the
        // picked vertex.
        for (unsigned v = 0; v < graph.size(); v++) {
            int edgeDistance = graph[nearestNode][v];
 
            if (edgeDistance > 0 && ((shortestDist + edgeDistance)<dist[v])) {
                parents[v] = nearestNode;
                dist[v] = shortestDist + edgeDistance;
            }
        }
    }

    cout<<"end"<<endl;
    
    printPath(airport_idx[dest], parents);
    cout<<endl;
    cout<< dist[airport_idx[dest]]<< "," <<graph[airport_idx["AER"]][airport_idx["KZN"]] << endl;
}


// vector<string> Graph::Asearch(string origin, string dest) {
//     Node* start = new Node(origin);
//     Node* end = new Node(dest);

//     // The set of nodes already evaluated
//     vector<Node*> closedSet;
//     unordered_map <Node*, int> distance;
//     // The set of currently discovered nodes that are not evaluated yet.
//     // Initially, only the start node is known.
//     vector<Node*> openSet;
//     openSet.push_back(start);
//     // For each node, which node it can most efficiently be reached from.
//     // If a node can be reached from many nodes, cameFrom will eventually contain the
//     // most efficient previous step.
//     unordered_map <Node*, Node*> cameFrom;
//     // For each node, the cost of getting from the start node to that node.
//     distance[start] = 0;
//     // For each node, the total cost of getting from the start node to the goal
//     // by passing by that node. That value is partly known, partly heuristic.
//     unordered_map <Node*, int> fScore;
//     // For the first node, that value is completely heuristic.
//     fScore[start] = heuristic_cost_estimate(start, end);

//     while (!openSet.empty()) {
//         Node* current = lowest_fScore(openSet, fScore);
//         if (current == end) {
//             return reconstruct_path(cameFrom, current);
//         }
//         openSet.erase(remove(openSet.begin(), openSet.end(), current), openSet.end());
//         closedSet.push_back(current);
//         vector<Node*> neighbors = get_neighbors(current);
//         for (unsigned i = 0; i < neighbors.size(); i++) {
//             Node* neighbor = neighbors[i];
//             if (find(closedSet.begin(), closedSet.end(), neighbor) != closedSet.end()) {
//                 continue;
//             }
//             int tentative_gScore = distance[current] + graph[airport_idx[current->airportID]][airport_idx[neighbor->airportID]];
//             if (find(openSet.begin(), openSet.end(), neighbor) == openSet.end()) {
//                 openSet.push_back(neighbor);
//             } else if (tentative_gScore >= distance[neighbor]) {
//                 continue;
//             }
//             cameFrom[neighbor] = current;
//             distance[neighbor] = tentative_gScore;
//             fScore[neighbor] = distance[neighbor] + heuristic_cost_estimate(neighbor, end);
//         }
//     }
//     return vector<string>();
// }

// vector<string> Graph::Kruskal() {
//     vector<string> mst;
//     vector<Edge> edges;
//     for (unsigned i = 0; i < graph.size(); i++) {
//         for (unsigned j = 0; j < graph[i].size(); j++) {
//             if (graph[i][j] != 0) {
//                 Edge e = Edge(i, j, graph[i][j]);
//                 edges.push_back(e);
//             }
//         }
//     }
//     sort(edges.begin(), edges.end());
//     DisjointSet ds = DisjointSet(graph.size());
//     for (unsigned i = 0; i < edges.size(); i++) {
//         int u = edges[i].src;
//         int v = edges[i].dest;
//         int set_u = ds.find(u);
//         int set_v = ds.find(v);
//         if (set_u != set_v) {
//             mst.push_back(getKey(airport_idx, u));
//             mst.push_back(getKey(airport_idx, v));
//             ds.merge(set_u, set_v);
//         }
//     }
//     return mst;
// }


