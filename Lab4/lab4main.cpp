#include <iostream>
using namespace std;
#include "dbiguint.h"
#include <string>
int main(){
  //dbiguint b;
  string x = "123456789";
  string y = "5000";
  string z = "5050";

  string add1 = "123000";
  string add2 = "132000";
  string add3 = "132000";

  dbiguint s = dbiguint(y);
  dbiguint t = dbiguint(z);
  dbiguint r = dbiguint(x);
  cout<<s.size()<<endl;
  cout<<s[3]<<endl;
  cout<<s<<endl;

  s.reserve(6);
  cout<<s<<endl;

  s+=t;
  cout<<s<<endl;

  s=t;
  cout<<s<<endl;
  cout<<t<<endl;

  t=r;
  cout<<t<<endl;
  cout<<r<<endl;
  dbiguint a1 = dbiguint(add1);
  dbiguint a2 = dbiguint(add2);
  //biguint a3 = biguint(add3);


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


dbiguint k;
cin >> k;

cout << k << endl;

  return 0;
}
