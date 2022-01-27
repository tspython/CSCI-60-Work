/*
* Author: Tushar Shrivastav
* File Name: dUSet.h
* Course: CSCI 60
*/

#ifndef DUSET_H
#define DUSET_H

#include <iostream>
#include "dynamicbag.h"

class dUSet: public DynamicBag {
  public:
  //constructors
  dUSet();
  dUSet(DynamicBag& b);
  //functions
  /*
  * Pre: none
  * Post: checks for duplicates
  *       if there are removes all of them
  *       calls DynamicBag insert on target
  */
  void insert(int target);
};

#endif
