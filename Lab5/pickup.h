#ifndef PICKUP_H
#define PICKUP_H
#include "automobile.h"
#include <string>

class Pickup: public Automobile {
  private:
    //member vars
    double hauling_capacity;
    bool extended_cab;
  public:
    //constructors
    Pickup();
    Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, double ihaulingcapacity, bool iextendedcab);

    //getters
    double get_hauling_capacity(){
      return hauling_capacity;
    }

    bool get_extended_cab(){
      return extended_cab;
    }

    //functions
    bool park(bool lot[], int size);
};


#endif // PICKUP_H
