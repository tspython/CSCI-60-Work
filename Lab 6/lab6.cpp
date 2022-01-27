#include <iostream>
using namespace std;

template <typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find){
  //t1 and t2 need to support the == operator to compare equality
  int count = 0;
  for (int i = 0; i < size; i++){
    if (find == a[i]){
      count++;
    }
  }
  return count;
}


template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high){
//t1 and t2 need to support comparasion operators
  //specifically >= and <= for count_range()
  int count = 0;
  for (int i = 0; i < size; i++){
    if(a[i] >= low && a[i] <= high){
      count++;
    }
  }
  return count;
}

int main(){
  int arr[] = {6,2,3,2,6,2};
  string stringArr[] = {"sigma","beta","sigma","alpha","beta","sigma"};
  string f = "sigma";
  string low = "alpha";
  string high = "sigma";

  //part 1 main
  int c = count_exact(arr, 6, 6);
  int d = count_exact(stringArr,6,f);
  cout << c <<endl;
  cout << d << endl;
  cout << "end of part 1 main" << endl;
  //end of part 1 main

  //part 2 main
  int c2 = count_range(arr,6,2,4);
  int d2 = count_range(stringArr,6,low, high);
  cout << c2 << endl;
  cout << d2 << endl;
  cout << "end of part 2 main" << endl;
  return 0;
}
