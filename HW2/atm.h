/*
* Filename: ATM.h
* Course: CSCI 60
* Author: Tushar Shrivastav
*/

#ifndef ATM_H
#define ATM_H
#include <iostream>
#include "BankAccount.h"

class Atm{
  private:
    int twenties_;
    int tens_;
  public:
    //constructors
    Atm();
    Atm(int tw, int te);

    //getters
    int twenties(){
      return twenties_;
    }

    int tens(){
      return tens_;
    }

    //function declarations
    /*
    * Pre: Takes in amount to withdraw from ATM, and a bank account object.
    *      Amount should be divisble by 10 and greater than 0
    * Post: Returns a bank account object, with withdrawn amount from balance.
    *       Prints number of 10s and 20s that have been withdrawn.
    */
    BankAccount get_cash(int amount, BankAccount b);

    /*
    * Pre: takes in ATM object
    * Post: overloads += operator
    */
    void operator +=(Atm& rhs);

    /*
    * Pre: takes in number of 20 bills and number of 10 bills
    * Post: adds number of new 20s and 10s to the 20s & 10s private members value
    */
    void restock(int new20s, int new110s);
};

/*
* Pre: takes in two ATM objects
* Post: returns true if both have equal amount of 10s and 20s,
*       else returns false
*/
bool operator ==(Atm lhs, Atm rhs);

/*
* Pre: takes in ostream refrence and atm object
* Post: returns ostream with appropriate print data
*/
std::ostream& operator <<(std::ostream& out, Atm a);


#endif
