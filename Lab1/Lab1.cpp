#include <iostream>
#include <string>
using namespace std;

struct Time{//military time, no am/pm
int hour;
int minute;
};

struct Carpool{
  string names[5];
  int num_people;
  Time arrived;
};

Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    return ret;
}

Carpool combineCarpool(Carpool car1, Carpool car2){
  Carpool newCarpool;

  if((car1.num_people + car2.num_people) <= 5)
  {
    newCarpool.num_people = car1.num_people + car2.num_people;
    for(int i = 0; i < car1.num_people; i++)
    {
      newCarpool.names[i] = car1.names[i];
    }
    int temp = 0;
    for(int j = car1.num_people; j < car1.num_people + car2.num_people; j++)
    {
      newCarpool.names[j] = car2.names[temp];
      temp++;
    }

    newCarpool.arrived = earlier(car1.arrived, car2.arrived);
  }
  else{
    cout << "There are more than 5 people in the car, return newCarpool." << endl;
  }

  return newCarpool;
}

int main(){
  //declaring structs
  Carpool car1, car2;
  Time t1, t2;

  //setting values

  string car1_names[3] = {"Bob", "John", "Alex"}; //, James, Rob
  string car2_names[1]= {"Jason"};   //, Joey, Nancy, Jake, Jack
  car1.num_people = 3;
  car2.num_people = 1;
  for (int i = 0; i < car1.num_people; i++)
    car1.names[i] = car1_names[i];

  for(int j = 0; j < car1.num_people; j++){
      car2.names[j] = car2_names[j];
  }

  t1.hour = 2;
  t1.minute = 15;
  t2.hour = 3;
  t2.minute = 10;
  car1.arrived = t1;
  car2.arrived = t2;

  //printing car 1 and car 2
  cout << "People in Car1: ";
  for(int i = 0; i < car1.num_people; i++ )
    cout <<car1.names[i] << " ";

  cout << endl;

  cout << "Car1 arrives at " << t1.hour << ":" << t1.minute <<endl;

  cout << "People in Car2: ";
  for(int j = 0; j < car2.num_people; j++ )
    cout <<car2.names[j] << " ";

  cout << endl;

  cout << "Car2 arrives at " << t2.hour << ":" << t2.minute <<endl;

  Carpool newcar = combineCarpool(car1, car2);

  //print array and new time
  cout << "People in newcar: ";
  for(int n = 0; n < newcar.num_people; n++ )
    cout <<newcar.names[n] << " ";
  cout << endl;

  cout << "New arrival time: " <<newcar.arrived.hour << ":" <<newcar.arrived.minute << endl;

  return 0;
}
