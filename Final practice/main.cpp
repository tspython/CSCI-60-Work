#include <iostream>
using namespace std;

template <typename T>
int binarySearch(int first, int last, T arr[], T value){
  int mid = (first + last) /2
  if(arr[mid] == value)
    return mid;
  if(arr[mid] > value)
    return binarySearch(first, mid-1, arr[], value);
  else
    return binarySearch(mid+1, last, arr[], value);
  return -1;
}

int main(){
  return 0;
}
