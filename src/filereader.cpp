#include "filereader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

FileData::FileData() {}

void FileData::readAirports(const string &airportFile)
{
    vector<string> row;
    string line, word;

    fstream file(airportFile, ios::in);
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
            Airport *temp = new Airport(row[4], stod(row[6]), stod(row[7]));
            airports[row[4]] = temp;
        }
    }
}

void FileData::readRoutes(const string &routeFile)
{
    vector<string> row;
    string line, word;

    fstream file(routeFile, ios::in);
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
            if (airports.find(row[2]) != airports.end() && airports.find(row[4]) != airports.end())
            {
                Route *temp = new Route(airports[row[2]], airports[row[4]]);
                routes.push_back(temp);
            }
        }
    }
}