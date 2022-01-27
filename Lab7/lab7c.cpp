#include <iostream>
using namespace std;

//salary at time 0 = $50,000
//slary for n-1 is sn-1 then what is your salary for year n? = [Sn = (sn-1)*1.1 + 5000]

//recursive function
int salary(int n){
  if(n==0){
    return 50000;
  }
  else{
    return salary(n-1)*1.1 + 5000;
  }
}

int main(){
  cout << salary(1)  << endl;
  cout << salary(5) << endl;
  return 0;
}
