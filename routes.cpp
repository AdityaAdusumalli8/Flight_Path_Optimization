#include "routes.h"

using namespace std;

Route::Route(Airport* src, Airport* dest){
    _srcAirport = src; 
    _destAirport = dest; 
    _dist = calculateDist(_srcAirport, _destAirport);
}

Route::Route(const Route& other){
  _srcAirport = other._srcAirport; 
  _destAirport = other._destAirport; 
  _dist = other._dist;
}

Route:: ~Route() {
  delete _srcAirport; 
  delete _destAirport; 
} 

// bool Route::operator==(const Route& other) const {
//     return (_srcAirport == other._srcAirport && _destAirport == other._destAirport;) ;
// }

//calculates distance using formula for distance between two points 
double Route::calculateDist(Airport* src, Airport* dest){
    double x_dist = dest->coordinates.first - src->coordinates.first;
    double y_dist = dest->coordinates.second - src->coordinates.second;
    x_dist *= x_dist;
    y_dist *= y_dist;
    return x_dist + y_dist;
}