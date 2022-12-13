# cs225-group225-Final-Project

# Github Organization: 

The physical location of all major files and deliverables will be listed here below:

**Code:**

Our 'src' folder will contain the majority of our code for this project. Within this folder you will find the following files:

- airport.cpp
- airport.h
- routes.cpp
- routes.h
- filereader.cpp
- filereader.h
- graph.cpp
- graph.h 

Of these files, our graph.cpp/graph.h files are the most important. Within these files is the crux of our project as it is responsible for holding our code for graph initialization, djisktra's algorithm, and eulerian path identification. 

The remaining files hold our code for data parsing and our airports and routes constructors. 


**Tests:**

The test cases we developed for our code will be found within the 'tests' folder.

**Data:**

The data we use is stored in the form of csv files within the 'tests' folder.

**Other Deliverables:**

The remaining deliverables (project proposal, team contract, written report, presentation slides and submission video) can be found in the general project directory.


# Running Instructions

1) Clone repository to your local dekstop
3) Open the folder in Visual Studio Code
4) If there is already a build directory within the folder delete it
6) Open a new terminal within the VS Code window
7) run "mkdir build" in the terminal
8) Once the build directory is created navigate into it with "cd build"
9) Once in the 'build' folder, run the following command: "cmake .." 
10) Afterwards, run "make" to compile the code
11) To execute test cases run: "./test"
12) To test manually, run: "./main"
13) You will be prompted to enter a source and destination airport id
14) If a path exists, you will be prompted to find the shortest path with dijkstras
15) Comment out the bfs and dijkstras section and uncommnt the eulerian path section
16) Run "./main" to check eulerian now


# Link to Presentation Slides + Video

https://docs.google.com/presentation/d/1IXGVNO2ID_qt_u0cOyg3Br18dIjAiCwtW6Mc73xvi1M/edit?usp=sharing

