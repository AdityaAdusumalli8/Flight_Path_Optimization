#include "airport.h"
#include <string>
#include <vector>

using namespace std;

Airport::Airport(string air_id, double longitude, double latitude) {
    airport_ID = air_id;
    coordinates.first = latitude;
    coordinates.second = longitude;
}

Airport::Airport(const Airport& other) {
    coordinates.first = other.coordinates.first;
    coordinates.second= other.coordinates.second;
    airport_ID = other.airport_ID;
}

// bool operator==(const Route &other){ return (airportID == other.airport_ID);}

void Airport::setAirportID(string s_id) {
    if (s_id=="") return;
    else airport_ID = s_id;
}

void Airport::setLongitude(double new_long) {
    //if(new_long==NULL) return;
    coordinates.second = new_long;
}

void Airport::setLatitude(double new_lat) {
    //if(new_lat==NULL) return;
    coordinates.first = new_lat;
}