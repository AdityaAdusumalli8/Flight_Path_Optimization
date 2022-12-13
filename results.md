## Leading Question 
Our goal for this project is to build a tool where a person can search for the shortest path between 2 destinations or multiple destinations. We will use a dataset of all the flight routes to create a graph where each node is an airport and the children are destinations from the current airport. We will use Dijkstra's algorithm to get the shortest route between two airports and use the Eulerian algorithm to check if there is a Eulerian path where we are traversing every edge only once. This will help the user plan an efficient trip as they can avoid flying over the same route multiple times.

## Dataset Acquisition
We will use the open flights routes and airport search datasets. To acquire the data we simply have to download the two datasets from the open flights website (https://openflights.org/data.html). 

## Data Format
The format of the data will be csv and we will have 2 csv files, one for each dataset. The datasets are large but we will be using all the airports. From the routes dataset, we will look at the source and destination airports and in the airport search dataset, we will use the coordinates to calculate the distance between airports. We won't be using any of the other data. 

## Data Correction
We are only using three fields of data which are the source airport, destination airport and the coordinates for each airport. We will omit all the unnecessary columns of data not being used. In the data we are looking at, there aren't any null values because every airport obviously has longitude and latitude coordinates. Therefore there is no need to correct any data because there won't be any null values. 

## Data Storage
We will store all the data in a directed and edge weighted graph. We will represent the graph using an adjacency matrix. The adjacency matrix will be an nxn matrix where n is the number of airports and each element in the matrix represents the weight. The weight of each edge is the distance property and it will be derived by using the haversine formula where x2 and x1 are the longitudes of the destination and source airports while y2 and y1 are the latitudes. An element in the matrix at index [i][j] would be the distance between airports i and j where each index represents an airport. The space complexity or storage cost of this graph will be O(V^2) where V is the number of airports.

## Algorithm 

To traverse a graph, we will utilize a BFS (breadth-first search) algorithm. A call to this function will include the source airport and the destination airport as parameters and its output will be a boolean value which returns true if a path exists between the two airports and false otherwise. The time complexity for this function is O(V^2), where V represents the number of vertices. The space complexity for our BFS function is O(|V|).  

We will have two functions, one for the Dijkstra's algorithm and one for the Eulerian path algorithm.

For the shortest path between two airports, we will use the Dijstrka’s algorithm which will take in a string for source airport and destination airport as input. The heuristic for the Dijkstra's algorithm will be the distance we calculate between the source and destination airport. The output for this function is an integer value of the shortest distance calculated between the source and destination airports. The function also prints to the terminal the shortest path using a printPath helper function. The time complexity for the function is O(V^2) where V is the number of vertices. Likewise, the space complexity for this algorithm on our adjacency matrix will also be O(V^2). 

Finally, we will be using the Eulerian Path algorithm to find a path through every edge given a list of routes. A Eulerian path is a path such that you are traversing every edge exactly once. This can be used to plan a trip between multiple destinations because you don’t want to go on the same route numerous times. The Eulerian function will take in the number of airports as input and a list of routes and airports which will be written in two csv files. The routes must be in a csv file because we don’t want more airports than are seen in the routes, otherwise there will be many unconnected, disjoint nodes in the graph. The function will return a vector of strings with the path of the airport ids. The time complexity for this function is O(E) where E is the number of edges. The space complexity will be O(V).

## Timeline

11/06-11/12:

     - Data acquisition
     
     - Data processing
     
     - Data cleaning
     
     - Data reading
     
     - Create class structure
     
     - Complete constructor, copy constructor, destructor
     
11/13 - 11/19:

    - Complete traversal algorithm
    
    - Develop test cases for constructor, copy constructor and traversal algorithm
    
    - Preapre for mid-project check-in
    
11/20 - 11/27:

    - Complete A* search algorithm 
    
    - Develop test cases for A* search algorithm
    
11/28 - 12/08:

    - Complete Kruskal's algorithm
    
    - Develop test cases for Kruskal's algorithm
    
    - Debug code and ensure all test cases are being passed
    
    - Make code cleaner
    
    - Prepare final project deliverables
    
    - Submit project
    
## Updated Timeline

Since we decided to switch our algorithms pretty last minute, here is a timeline of when our finalized algorithms were written and the timeline it followed:

12/08 - 12/12
     
     - Complete Dijkstra's algorithm
     
     - Complete Eulerian Path Identification Algorithm
     
     - Write test cases for both algorithms
     
     - Finish write up, presentation and other final project deliverables
     
     - Fix Project Proposal