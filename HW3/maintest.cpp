#include <iostream>
using namespace std;

int main(){
  //Draw the memory picture for the code below, up until the next comment
  int * p1, n1=53, *p2, n2=72, *p3;
  double *p4, n4=6.3;

  p1 = &n1;
  p2 = &n2;
  p3 = p1;
  *p3 = 35;
  n2 = 21;
  p4 = &n4;

  //which of the following do or don't compile?  Why or why not?
  n4 = n1;
  n1 = n4;

  //p1 = p4;

  //p2 = &p1

  //p4 = &n1;

  //&n1 = &n2;
  *p1 = *p2;

  return 0;
}
