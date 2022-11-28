#include "graph.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>


using namespace std;

Graph::Graph()
{
    
}

Graph::Graph(const string &airportDataSet, const string &routesDataSet) {

}


Graph::~Graph()
{
    //dtor
}

// void Graph::addEdge(int v, int w)
// {
//     adj[v].push_back(w); // Add w to v’s list.
// }

// void Graph::BFS(int s)
// {
//     // Mark all the vertices as not visited
//     bool *visited = new bool[V];
//     for(int i = 0; i < V; i++)
//         visited[i] = false;

//     // Create a queue for BFS
//     list<int> queue;

//     // Mark the current node as visited and enqueue it
//     visited[s] = true;
//     queue.push_back(s);

//     // 'i' will be used to get all adjacent vertices of a vertex
//     list<int>::iterator i;

//     while(!queue.empty())
//     {
//         // Dequeue a vertex from queue and print it
//         s = queue.front();
//         cout << s << " ";
//         queue.pop_front();

//         // Get all adjacent vertices of the dequeued vertex s
//         // If a adjacent has not been visited, then mark it visited
//         // and enqueue it
//         for(i = adj[s].begin(); i != adj[s].end(); ++i)
//         {
//             if(!visited[*i])
//             {
//                 visited[*i] = true;
//                 queue.push_back(*i);
//             }
//         }
//     }
// }
// // A* (pronounced "A-star") is a graph traversal and path search algorithm, which is used in many fields of computer science due to its completeness, optimality, and optimal efficiency.[1] One major practical drawback is its {\displaystyle O(b^{d})}O(b^d) space complexity, as it stores all generated nodes in memory. Thus, in practical travel-routing systems, it is generally outperformed by algorithms which can pre-process the graph to attain better performance,[2] as well as memory-bounded approaches; however, A* is still the best solution in many cases.[3]
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

// }



