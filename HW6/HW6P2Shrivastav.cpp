#include "n_dimension_point.h"
#include <iostream>
#include <cassert>
using namespace std;

/*
* Pre: none
* Post: return result of distance formula
*/
template <typename T>
double distance(n_dimension_point<T> pa, n_dimension_point<T> pb){
  assert(pa.getSize() == pb.getSize());
  double distance = 0;
  for(int i = 0; i < pa.getSize(); i++)
    distance += pow(pb.getItem(i) - pa.getItem(i), 2); //MUST SUPPORT - OPERATOR
  return std::sqrt(distance);
}

/*
* Pre: none
* Post: return distance between encodings of first characters of the strings
*/
int operator -(std::string sa, std::string sb){
  int difference = (int)(sa.front() - sb.front());
  return difference;
}

int main(){
  //part 3 main
  int int_arr[] = {1,4};
  int int_arr2[] = {2,5};
  std::string str_arr[] = {"russia", "usa", "mexico", "canada", "brazil"};
  std::string str_arr2[] = {"great", "amazing", "wow", "cool", "breeze"};
  n_dimension_point<int> p = n_dimension_point<int>(int_arr,2);
  n_dimension_point<int> p2 = n_dimension_point<int>(int_arr2,2);
  n_dimension_point<std::string> s = n_dimension_point<std::string>();
  n_dimension_point<std::string> s2 = n_dimension_point<std::string>(str_arr,5);
  n_dimension_point<std::string> s3 = n_dimension_point<std::string>(str_arr, 5);
  n_dimension_point<std::string> s4 = n_dimension_point<std::string>(str_arr2, 5);

  //Question 2 in HW 6
  //testing += overload

  cout << "Before: " ;
  for(int i = 0; i < s3.getSize(); i++)
    cout<<s3.getItem(i) << " ";
  cout << endl;
  s3+=s4;

  cout << "Testing += Overload: " ;
  for(int i = 0; i < s3.getSize(); i++)
    cout<<s3.getItem(i) << " ";
  cout << endl;

  //testing + and == operators
  //+ operator
  s = s3 + s4;
  cout << "Testing + Overload: " ;
  for(int i = 0; i < s.getSize(); i++)
    cout<<s.getItem(i) << " ";
  cout << endl;

  //== operator
  cout << "S3 equal to S4? :" << (s3 == s4) << endl; // 0 for false

  //testing distance function between two points
  //int
  cout << distance(p2, p) << endl;

  //string
  cout<< distance(s2, s4);

  //end of problem 2

  return 0;
}
