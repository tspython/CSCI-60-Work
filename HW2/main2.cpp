/*
* Filename: main2.cpp
* Course: CSCI 60
* Author: Tushar Shrivastav
*/
#include <string>
#include <iostream>
#include "atm.h"
#include "bankaccount.h"
using namespace std;

int main(){
  Atm a = Atm(40, 50);
  Atm c = Atm(10, 30);
  Atm d = Atm(10, 30);
  Atm b;
  Atm e;
  BankAccount bank = BankAccount(1, 1000, 1, "Alpha");
  BankAccount bank2 = BankAccount(1, 2, 1, "Alpha");

  //testing == operator overload
  cout << (a == c) << endl;
  cout << (d == c) << endl;

  //testing print
  (cout << a) << endl;

  //testing restock
  cout<< "Before: ";
  (cout << b) << endl;
  b.restock(10, 10);
  cout<< "After: ";
  (cout << b) << endl;

  //testing += operator
  cout<< "Before: ";
  (cout << c) << endl;
  c+=b;
  cout<< "After: ";
  (cout << c) << endl;
  (cout << b) << endl;

  //testing get_cash
  cout<< "Before: ";
  (cout << a) << endl;
  (cout << bank) << endl;
  bank = a.get_cash(50, bank);
  cout<< "After: ";
  (cout << a) << endl;
  (cout << bank) << endl;

  //testing pre condition for get_cash
  bank = a.get_cash(51, bank);
  bank = a.get_cash(-1, bank);
  bank = e.get_cash(10, bank); //testing not enough funds condition

  return 0;
}
