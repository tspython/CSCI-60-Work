#include "pickup.h"
#include <string>

Pickup::Pickup()
: Automobile(){

  hauling_capacity=0;
  extended_cab = false;
}


Pickup::Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, double ihaulingcapacity, bool iextendedcab)
: Automobile(imake,imodel ,iyear ,iprice, istall){
  hauling_capacity=ihaulingcapacity;
  extended_cab = iextendedcab ;
}

bool Pickup::park(bool lot[], int size){
  int spot=size;
  for(int i=1; i<size; i++){
      if(!lot[i] && !lot[i-1])
          spot = i-1;
  }
  if(spot > size - 1)
     return false;
  else{
      Automobile::set_stall(spot);
      lot[spot] = true;
      lot[spot + 1] = true;
      return true;
  }
}
