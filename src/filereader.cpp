#include "filereader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;
FileData::FileData() {}

void FileData::readAirports(const string &airportFile)
{
    vector<string> row;
    string line, word;
    
    //open input file stream
    ifstream file(airportFile);

    if (file.is_open())
    {
        //iterate through each line
        while (getline(file, line))
        {
            //after each iteration row vector will be populated with data from the curr line
            //therefore we have to clear it so we look at one line at a time
            row.clear();
            stringstream str(line);
            //iterate through each word in the line separated by comma
            while (getline(str, word, ','))
            {
                //index of row vector represents the column
                row.push_back(word);
            }
            try {
                //remove quotes from airport id string
                row[4].erase(remove(row[4].begin(), row[4].end(), '"'), row[4].end());
                //create new airport object with data from row vector
                Airport *temp = new Airport(row[4], stod(row[6]), stod(row[7]));
                //add to the hashmap with id as key and airport object as value
                airports[row[4]] = temp;
            }
            catch(...){
                //some of the coordinate data is null so when converting to double an error is thrown
                //to handle null data we catch the error and simply move on to the next airport
                continue;
            }     
        }
    }
}

void FileData::readRoutes(const string &routeFile)
{
    vector<string> row;
    string line, word;

    //read file same as above
    ifstream file(routeFile);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();
            stringstream str(line);
            while (getline(str, word, ','))
            {
                row.push_back(word);
            }

            //if the src and dest airport ids are found in the hashmap
            if (airports.find(row[2]) != airports.end() && airports.find(row[4]) != airports.end())
            {
                //get the airport objects associated to ids and create route object
                Route *temp = new Route(airports[row[2]], airports[row[4]]);
                //add route to routes vector
                routes.push_back(temp);
            }
        }
    }
}