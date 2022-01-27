#include <iostream>
using namespace std;


int EvenSum(int n){
  if(n==1){
    return 2;
  }
  else{
    return 2*n + EvenSum(n-1);
  }
}

int ncounter(int a[], int size, int n){
  if(size==0){
    return;
  }
  else{
    if(a[size] == n)
      return 1 + ncounter(a, size-1, n);
    return ncounter(a, size-1, n);
  }
}

int main(){
  cout << EvenSum(3)<<endl;
  return 0;
}
