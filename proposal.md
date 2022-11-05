## Leading Question 
Our goal for this project is to build a tool where a person can search for the shortest path between 2 destinations or multiple destinations. We will use a dataset of all the flight routes to create a graph where each node is an airport and the children are destinations from the current airport. We will use A* search Algorithm to get the shortest route between two airports and Kruskal's algorithm to find the shortest path between multiple airports.  

## Dataset Acquisition
We will use the open flights routes and airport search datasets. To acquire the data we simply have to download the two datasets from the open flights website (https://openflights.org/data.html). 

## Data Format
The format of the data will be csv and we will have 2 csv files, one for each dataset. The datasets are large but we will be using all the airports. From the routes dataset, we will look at the source and destination airports and in the airport search dataset, we will use the coordinates to calculate the distance between airports. We won't be using any of the other data. 

## Data Correction
We are only using three fields of data which are the source airport, destination airport and the coordinates for each airport. We will ommit all the unnecessary columns of data not being used. In the data we are looking at, there aren't any null values because every airport obviously has longitude and latitude coordinates. Therefore there is no need to correct any data because there won't be any null values. 

## Data Storage
We will store all the data in a directed and edge weighted graph. Each node in the graph will be an airport and the children of the node will be an edge class which has a distance property and a pointer to the node of the destination airport. The space complexity or storage cost of this graph will be O(n+m) where n is the number of airports and m is the number of routes or edges between the nodes. 

## Algorithm 
We will have two functions, one for the A* search algorithm and one for Kruskal's algorithm. For the shortest path between two airports, the function will take a source airport, destination airport and graph structure as input. The heuristic for the A* search algorithm will be the distance we calculate between the source and destination airport. The output for this function is a vector of the airport nodes you go through, starting with the source airport ending at the destination airport. The time complexity for the function is O(n^m) where n is the number of children edges and m is maximum depth. The space complexity is the same O(n^m). for A print function can be used to print the path with arrows to the next airport based on the output vector as input. 

For the shortest path between multiple airports, the function will take a vector of airports and the entire graph as inputs. The output will be a vector of all the edges used to connect the input nodes. The time complexity for this function is O(m*log(n)) where m is the number is of edges or routes and n is the number of nodes or airports. The space complexity is O(log(m)). 


## Timeline

