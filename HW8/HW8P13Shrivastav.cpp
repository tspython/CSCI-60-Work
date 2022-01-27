#include <iostream>
using namespace std;

//problem 1
 int sequence(int n){
   if(n<=1){
     return 1;
   }
   else{
     return (n-1) + sequence(n-2);
   }
 }

//problem 3
void reverse(int a[], int first, int last){
  if(first >= last)
    return;
  else{
    int temp = a[first];
    a[first] = a[last];
    a[last] = temp;
    reverse(a, first+1, last-1);
  }
}


int main(){
  //problem 1
  cout << sequence(5) << endl; //SHOULD OUPUT 7

  //problem 3
  int arr[10];

  for(int i = 0; i<10; i++)
    arr[i] = rand()%10; //fill array with random numbers

  cout<< "Before: ";
  for(int i = 0; i<10; i++)
    cout<<arr[i] << ", ";
  cout << endl;

  reverse(arr, 0, 9); //reverses array, so print after will be reversed

  cout<< "After: ";
  for(int i = 0; i<10; i++)
    cout<<arr[i] << ", ";
  cout << endl;


  return 0;
}
