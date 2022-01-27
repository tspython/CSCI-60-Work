#include <iostream>
#include "lbiguint.h"
using namespace std;

int main(){
  lbiguint l = lbiguint("123456789");
  lbiguint l2 = lbiguint("123456");

  cout << l << endl;
  cout << l2 << endl;
  l = l2;

  cout << l2 << endl;



  return 0;
}
