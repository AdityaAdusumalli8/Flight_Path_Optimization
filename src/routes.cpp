#include "routes.h"
#include <cmath>

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
  long double one_deg = (M_PI) / 180;
  long double lat1 = src->coordinates.first;
  long double long1 = src->coordinates.second;
  long double lat2 = dest->coordinates.first;
  long double long2 = dest->coordinates.second;

  //convert to radians
  lat1 = lat1 * one_deg;
  long1 = long1 * one_deg;
  lat2 = lat2 * one_deg;
  long2 = long2 * one_deg;

  //Haversine Formula
  long double dlong = long2 - long1;
  long double dlat = lat2 - lat1;
  long double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
 
  ans = 2 * asin(sqrt(ans));
 
  long double R = 6371;
     
  ans = ans * R;
  return ans;
}
