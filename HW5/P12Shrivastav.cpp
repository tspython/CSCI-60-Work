#include <iostream>
#include "dSet.h"
#include "dUSet.h"
#include "dynamicbag.h"

using namespace std;

int main(){

  //PROBLEM 1 MAIN TESTER
  int arr[] = {1, 1, 3, 2, 7, 4, 5, 4};
  DynamicBag bag  = DynamicBag(arr, 8);
  cout << bag << endl; // printing bag before it becomes a dUSet
  dUSet u = dUSet(bag); //takes bag and creates a dUSet that has no duplicates that bag has
  cout << u << endl;
  //END OF PROBLEM 1 MAIN TESTER

  //testing dUSet insert function
  u.insert(1);
  cout << u << endl;

  //PROBLEM 2 MAIN TESTER
  cout << bag << endl;
  dSet s = dSet(bag); // convert bag to dSet
  cout << s << endl; // will be sorted and remove duplicates

  s.insert(6); //adds 6 between 5 and 7
  cout << s << endl;

  //END OF PROBLEM 2 MAIN TESTER
}
