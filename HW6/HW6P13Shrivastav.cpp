#include <iostream>
using namespace std;

/*
* Pre: none
* Post: return the greater of b-a or a-b
*/
template <typename T>
T abs(T a, T b);

/*
* pre: none
* post: return the most frequent T1 in array passed
*/
template <typename T1>
T1 frequent(T1 a[], std::size_t size);

template <typename T>
T abs(T a, T b){
  if(a - b > b - a) // must support > operator (comparative)
    return a-b;    //also must support subtraction operation
  else
    return b-a;
}

template <typename T1>
T1 frequent(T1 a[], std::size_t size){
  int count = 0;
  T1 greatest_T;
  for(int i = 0; i < size; i++){
    int countBefore = count;
    count = 0; //reset count to count new one
    for(int j = 0; j < size; j++){
      if(a[i] == a[j]) //MUST SUPPORT == COMPARASION OPERATOR
        count++;
    }
    if(count > countBefore)
      greatest_T = a[i];
  }
  return greatest_T;
}


int main(){
  //testing problem 1
  cout<< abs(5,6) << endl;

  //testing problem 3
  int arr[6] = {3,2,7,3,2,2};
  cout << frequent(arr, 6) << endl;
  return 0;
}
