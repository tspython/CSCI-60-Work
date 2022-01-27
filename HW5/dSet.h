/*
* Author: Tushar Shrivastav
* File Name: dSet.h
* Course: CSCI 60
*/

#ifndef DSET_H
#define DSET_H

#include <iostream>
#include "dynamicbag.h"
#include "dUSet.h"

class dSet: public dUSet {
  public:
  //constructors
  dSet();
  dSet(DynamicBag& b);
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
