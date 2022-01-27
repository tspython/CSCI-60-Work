#include <iostream>
#include <vectors>
#include <algorithms>
#include <fstream>
using namespace std;

struct Carpool{
  set<string> names;
  int month;
  int day;
}

int main(){
  vector<Carpool> carpool_vector;
  map<string, map<int, int>> carpool_map;

  ofstream myfile;

  myfile.open("carpool.txt");

  string names;
  while(!myfile.eof()){

  }
  myfile.close();
  return 0;
}
