#include "n_dimension_point.h"
#include <iostream>
using namespace std;

int main(){
  //part 3 main
  int int_arr[] = {1,4,7,6,2};
  std::string str_arr[] = {"russia", "usa", "mexico", "canada", "brazil"};
  n_dimension_point<int> p = n_dimension_point<int>(int_arr,5);
  n_dimension_point<std::string> s = n_dimension_point<std::string>();
  n_dimension_point<std::string> s2 = n_dimension_point<std::string>(5);
  n_dimension_point<std::string> s3 = n_dimension_point<std::string>(str_arr, 5);
  n_dimension_point<std::string> s4 = n_dimension_point<std::string>();
  s4 = s3;

  cout << p.getSize() << endl;
  cout << s3.getItem(0) << endl;
  cout << s3.getSize() << endl;
  cout << s4.getItem(0) << endl;
  cout << s4.getSize() << endl;

  return 0;
}
