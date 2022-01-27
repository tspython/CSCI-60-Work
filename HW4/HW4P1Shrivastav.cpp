/*
* Author: Tushar Shrivastav
* Course: CSCI 60
* Filename: HW4P1Shrivastav.cpp
*/
#include <iostream>
using namespace std;

//prototype
void swap(int *a, int *b);

int main(){
    int a, b, * x, * y;
    a = 10;
    b = 5;
    x = &a;
    y = &b;

    cout<<"a is: "<<a<<", b is: "<<b<<endl;
    cout<<"*x is: "<<*x<<", *y is: "<<*y<<endl;
    swap(x, y);
    cout<<"a is: "<<a<<", b is: "<<b<<endl;
    cout<<"*x is: "<<*x<<", *y is: "<<*y<<endl;
    return 0;
}

/*
* pre: none
* post: swaps pointers and memory of args
*/
void swap(int *a, int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
