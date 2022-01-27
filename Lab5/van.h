#ifndef VAN_H
#define VAN_H
#include "automobile.h"
#include <string>

class Van: public Automobile {
  private:
    //member variables
    int seats;
  public:
    //constructors
    Van();
    Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int iseats);
    //getters

    int get_seats(){
      return seats;
    }
    //functions
    bool park(bool lot[], int size);
};

#endif
