#include "filereader.h"
#include "graph.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    //CHECK BFS AND DIJKSTRAS WORK
    Graph g = Graph("../tests/airport.csv", "../tests/routes.csv");

    //uncomment if you want to print graph
    // for(unsigned i=0; i<g.graph.size(); i++){
    //     for(unsigned j=0; j<g.graph[i].size(); j++){
    //         cout<< g.graph[i][j] << ",";
    //     }
    //     cout<<endl;
    // }

    string src;
    string dest;

    cout << "Type the source airport id: ";
    cin >> src;
    cout << "Type the destination airport id: ";
    cin >> dest;
    if(g.airport_idx.find(src) == g.airport_idx.end() || g.airport_idx.find(dest)==g.airport_idx.end()){
        cout<<"Input valid airport ids" <<endl;
    }
    else{
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
    }


    //CHECK EULERIAN PATHFINDER WORKS
    //uncomment to test eulerian
    // Graph g = Graph("../tests/airports_eulerian.csv", "../tests/routes_eulerian.csv");
    // vector<string> path = g.eulerian(g.graph.size());
    // for (unsigned i=0; i<path.size(); i++){
    //     cout << path[i] << " -> ";
    // } 
    // cout<<endl;


    return 0;
} 