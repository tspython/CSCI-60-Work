/*
* Filename: ATM.cpp
* Course: CSCI 60
* Author: Tushar Shrivastav
*/

#include <string>
#include <iostream>
#include "atm.h"
#include "bankaccount.h"

//constructors
Atm::Atm(){
  twenties_ = 0;
  tens_ = 0;
}

Atm::Atm(int tw, int te){
  twenties_ = tw;
  tens_ = te;
}
//function implementations

BankAccount Atm::get_cash(int amount, BankAccount b){
   //handle cases where ATM Doesn't have enough bills, or
   //user requested an invalid amount
   //assert(amount >= 0);
   int a = amount;
   int wtw = 0;
   int wte = 0;
   if((amount % 10 != 0) || (amount <=0)){
     std::cout << "invalid amount" << std::endl;
     return b;
   }
   //check if atm does not have enough bills
   if((twenties_*20 + tens_ *10) < amount){
     ///cannot withrdraw not enough bills
     std::cout << "ATM does not have enough funds" << std::endl;
     return b;
   }

   //first withdraw 20s then withdraw 10s
   while(a>0){
     if(twenties_!= 0 && a>=20){
       //subtract balance by 20
       b.withdraw(20);
       a-=20;
       twenties_--;
       wtw++;
     }
     else if(tens_!=0){
       b.withdraw(10);
       a-=10;
       tens_--;
       wte++;
     }
   }
   //print out values and
   std::cout<< "Bills withdrawn: " << std::endl;
   std::cout << "Twenties: " << wtw << std::endl;
   std::cout <<  "Tens: " << wte << std::endl;
   return b;
}

void Atm::operator +=(Atm& rhs){
  //transfers all bills from the rhs to the ATM the func was called on
  //stock with transfered bills
  restock(rhs.twenties(), rhs.tens());
  rhs.twenties_ = 0;
  rhs.tens_ = 0;
}

void Atm::restock(int new20s, int new10s){
  //adds new twenties and new new110s
  twenties_ += new20s;
  tens_ += new10s;
}

bool operator ==(Atm lhs, Atm rhs){
  if( (lhs.twenties() == rhs.twenties() ) && (lhs.tens() == rhs.tens() ) )
    return true;
  return false;
}

std::ostream& operator <<(std::ostream& out, Atm a){
  out << "Twenties: " << a.twenties() << " and Tens: " << a.tens();
  return out;
}
