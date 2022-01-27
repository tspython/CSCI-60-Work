#include "automobile.h"
#include "pickup.h"
#include "van.h"
#include <iostream>
using namespace std;


int main(){
  //Part 1 Main
  bool carLot[] = {true, true, false, true, true, true, true, false, false, false};
  bool carLot2[] = {true, true, false, false, true, true, true, false, true, false};
  Automobile a = Automobile("Murcielago", "Ferrari", 2008, 3000000, -1);
  cout << a.park(carLot, 10) << "car parked status" <<endl;
  cout << a.stall() << "car stall" << endl;


  //Part 3 Main
  Pickup x;
  Pickup p = Pickup("Amogus", "Ford", 2019, 45000, -1, 2500, true);
  /cout << x.Automobile::make() << endl;
  cout << x.get_extended_cab() << endl;
  cout << p.Automobile::make() << endl;
  cout << p.get_extended_cab() << endl;
  cout << p.get_hauling_capacity() << endl;

  //Part 4 Main
  cout << p.park(carLot, 10)<< "pickup parked status" <<endl;
  cout << p.Automobile::stall() << endl;
  //cout << p.park(carLot2, 10)<< "pickup parked status" <<endl;

  //Part 5 Main
  Van v;
  Van q = Van("Mystery Wagon", "Ford", 2020, 40000, -1, 6);
  Van r = Van("Piece of Junk", "Koenigsegg", 1980, 40, -1, 8);

  cout << q.park(carLot2, 10) << endl;
  cout << r.park(carLot2, 10) << endl;

  for(int i = 0; i < 10; i++){
    cout << "parking space " << i << ": " << carLot2[i] << endl;
  }

  return 0;

}
