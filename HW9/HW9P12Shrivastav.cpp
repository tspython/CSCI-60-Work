#include <iostream>
#include "lbag.h"
#include "node_toolkit.h"
using namespace std;

int main(){

  LBag<int> a, b, c;

  //PROBLEM 1//
  //testing += and +

  a.insert(2);
  a.insert(3);
  a.insert(4);

  b.insert(1);
  b.insert(7);
  b.insert(8);

  cout<< a<< endl; //432
  cout << b << endl; //871

  a+=b;

  cout << a << endl; //432871

  c = a + b;

  cout << c << endl; //432871871
  //END OF PROBLEM 1

  //PROBLEM 2
  c.erase_one(2);
  cout << c << endl; //43871871

  c.erase(1);
  cout << c << endl; //347878


  return 0;
}
