#include "Rational.h"
#include <iostream>
using namespace std;

int main(){
  Rational r1 = Rational(4, 2), r2(3, 4), r5(6,8), r6(8,4);
  Rational r;
  //Rational r3 = r1.mult(r2);
  //testing *
  Rational r3 = r1*r2;//Think of as r1.*(r2)
  //testing *=
  r2*=r1;//r2.*=(r1)
  (cout<<r3.numer())<<"/"<<r3.denom()<<endl;
  cout<<"/"<<r3.denom()<<endl;
  cout<<r3<<endl;

  //testing reduce
  Rational r4 = r1;
  r4.reduce();
  (cout<<r4.numer())<<"/"<<r4.denom()<<endl;

  //testing == overload
  cout<< (r1==r6) <<endl;
  cout<< (r1==r5) <<endl;

  //testing +=
  cout<<"r5 Before:"<< endl;
  (cout<<r5) << endl;
  r5+=r6;
  cout<<"r5 After:"<< endl;
  (cout<<r5) << endl;

}
