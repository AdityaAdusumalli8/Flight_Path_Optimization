#include "filereader.h"
#include "graph.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    //Check BFS and dijkstras work
    Graph g = Graph("../tests/airports_small.csv", "../tests/routes_small.csv");
    cout<< g.graph[g.airport_idx["SFO"]][g.airport_idx["ORD"]] << endl;


    string src;
    string dest;

    cout << "Type the source airport id: ";
    cin >> src;
    cout << "Type the destination airport id: ";
    cin >> dest;
    if(g.BFS(src, dest)){
        string check;
        cout<<"We have verified a path exists with BFS" << endl;
        cout<<"Would you like to find the shortest path y or n: ";
        cin>> check;
        if(check == "y"){
            cout<< "The shortest path is ";
            int dist = g.dijkstra(src, dest);
            cout << "The distance is "<< dist << endl;
        }
        else if(check == "n"){
            cout<<"Thank you for your time!" << endl; 
        }
    }
    else{
        cout<< "We have verified no path exists with BFS" << endl;
    }


    //Check eulerian pathfinder works
    // Graph g = Graph("../tests/airports_eulerian.csv", "../tests/routes_eulerian.csv");
    // vector<string> path = g.eulerian(g.graph.size());
    // for (unsigned i=0; i<path.size(); i++){
    //     cout << path[i] << " -> ";
    // } 
    // cout<<endl;


    return 0;
} 