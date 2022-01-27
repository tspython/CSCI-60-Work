/*
  Filename: HW1P2Shrivastav.cpp
  Course: CSCI 60
  Author: Tushar Shrivastav
*/

#include <iostream>
#include <string>
using namespace std;

struct Animal{
  string name;
  string gender;
  string type;
  double age;
  double price;
};

//prototypes
Animal cheapest(string type, Animal a[], int size);
bool livetogether(Animal a, Animal b);

int main(){

  Animal animal_shelter[6];
  animal_shelter[0] = {"Alpha", "Male","Dog", 1, 500};
  animal_shelter[1] = {"Beta", "Male","Cat", 5, 300};
  animal_shelter[2] = {"Delta", "Male","Cat", 3, 600};
  animal_shelter[3] = {"Gamma", "Male","Dog", 2, 700};
  animal_shelter[4] = {"Omega", "Male","Cat", 8, 100};
  animal_shelter[5] = {"Sigma", "Male","Dog", 7, 400};

  Animal inexpensive = cheapest("Dog", animal_shelter, 6);
  cout<< inexpensive.name << endl;

  return 0;
}

Animal cheapest(string type, Animal a[], int size){
  Animal cheapest;

  for(int i = 0; i < size; i++){
    if(a[i].type == type){ //check if it is the type passed
      for(int j = i + 1; j < size; j++){
        if (livetogether(a[i], a[j])){ //make sure they are the same type
          if(a[i].price < a[j].price) // check if it
            cheapest = a[i];
          else
            cheapest = a[j];
        }
      }
    }
  }
  return cheapest;
}

bool livetogether(Animal a, Animal b){
  if (a.type == b.type) //check if same type
        return true;
  return false;
}
