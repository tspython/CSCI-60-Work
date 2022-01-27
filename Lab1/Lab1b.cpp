#include <iostream>
#include <string>
using namespace std;

struct Time{//military time, no am/pm
int hour;
int minute;
};

class Carpool{
  public:
    string names[5];
    int num_people;
    Time arrived;

    Carpool(string n[], int np, Time arr){
      //int len = sizeof(n)/sizeof(n[0]);
      for( int i = 0; i < np; i++){
        names[i] = n[i];
      }
      num_people = np;
      arrived = arr;
    }

    Carpool(){
      names[0];
      num_people = 0;
      arrived;
    }

    void print(){
      cout << "People in car: ";
      for(int i = 0; i < num_people; i++){
        cout << names[i] << " ";
      }
    }
};


int main(){
  string car1_names[3] = {"Bob", "John", "Alex"};
  Time t;
  t.hour = 3;
  t.minute = 15;
  Carpool car1 = Carpool(car1_names, 3, t);

  car1.print();
}
