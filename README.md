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

The remaining deliverables (project proposal, team contract, written report, presentation slides and submission video) can be found in the 'deliverables' folder.


# Running Instructions

1) Clone repository to your local dekstop
2) Open the folder in Visual Studio Code
3) Open a new terminal within the VS Code window
4) Navigate into the 'build' folder
5) Once in the 'build' folder, run the following command: "cmake .." 
6) From here, to run test cases type the following commond: "make tests"
7) To execute test cases run: "./test"
