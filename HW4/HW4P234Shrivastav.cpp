#include <iostream>
using namespace std;
#include "dbiguint.h"
#include <string>
int main(){

  //PROBLEM 2 MAIN TESTER

  string x = "123456789";
  string y = "5000";
  string z = "5050";


  string add1 = "123000";
  string add2 = "132000";
  string add3 = "132000";

  dbiguint s = dbiguint(y);
  dbiguint t = dbiguint(z);
  dbiguint r = dbiguint(x);
  dbiguint a1 = dbiguint(add1);  //123000
  dbiguint a2 = dbiguint(add2); //132000

  //tesinng [] overload
  cout<<s[3]<<endl;
  //testing assignment operator (=) overload
  cout<< "Before: ";
  cout<<s<<endl;
  s=t;
  cout<<"s after = to t(5050): " << s <<endl;

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

  //testing >> operator overload
  dbiguint k;
  cout<<"Please enter a string of numbers: " << endl;
  cin >> k;
  cout<<"Printing inputted value: " << endl;
  cout << k << endl;

  // END OF PROBLEM 2 MAIN TESTER

  // PROBLEM 3 MAIN TESTER
  string five = "1577";
  string six = "1635";
  dbiguint fiv = dbiguint(five);
  dbiguint si = dbiguint(six);
  dbiguint dif;

  //testing - operator overload
  dif = si-fiv;
  cout << dif << endl;

  //testing -= operator overload
  dif = si;
  si-=fiv;
  cout << si << endl;
  si = dif;

  //testing *=
  si *= fiv;
  cout << si << endl;
  si = dif;

  //testing * function
  dbiguint product;
  product = si * fiv;
  cout << product << endl;
  // END OF PROBLEM 3 MAIN TESTER

  return 0;
}
