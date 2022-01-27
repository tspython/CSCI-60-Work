#include <iostream>
#include "bag10.h"
using namespace std;

int main(){
  int arr[] = {5, 4, 2, 7, 9};
  bag b = bag(arr, 5);
  /*
  for(auto e:b){
    cout << e << endl;
  }
  */
  /*bag_iterator<int> biter = b.begin();
  cout << *(++biter) << endl;
  */
  for(bag<int>::iterator i = b.begin(); i != b.end(); ++i){
  cout << *i <<" ";
  }
  cout<< endl;


  return 0;
}
