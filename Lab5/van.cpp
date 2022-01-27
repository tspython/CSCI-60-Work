#include "van.h"
#include <string>


Van::Van()
: Automobile(){
  seats = 0;
}


Van::Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int iseats)
: Automobile(imake,imodel ,iyear ,iprice, istall){
  seats = iseats;
}


bool Van::park(bool lot[], int size){
  if(seats <= 7){
    return (Automobile::park(lot, size));
  }
  else{
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
}
