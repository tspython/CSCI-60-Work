#include <iostream>
using namespace std;
#include "biguint.h"
#include <string>
int main(){
  biguint b;
  biguint c;
  string x = "123456789";
  string add1 = "123000";
  string add2 = "129000";
  string add3 = "132000";
  biguint s = biguint(x);
  biguint a1 = biguint(add1);
  biguint a2 = biguint(add2);
  biguint a3 = biguint(add3);
  //Problem 2 Portion of Main
  b = a1 + a2; // with a carry over
  cout << b << endl;

    //testing  compare()
  // <
  cout << (a1<a2) << endl; // true (1)
  // <=
  cout << (a2<=a1) << endl; //false (0)
  // !=
  cout<< (a2!=a1) << endl; // true (1)
  // ==
  cout << (a2==a1) << endl; //false (0)
  // >=
  cout << (a2>=a1) << endl; //true (1)
  // >
  cout << (a1>a2) << endl; //fasle (0)

  //Problem 3 Portion of Main
  // -
  c = a3-a1;
  cout << c << endl;
  // -=
  a3-=a2;
  cout << a3 << endl;

  //Problem 4 Portion of main
  string obj = s.to_string();
  cout << obj << endl;
  return 0;
}
