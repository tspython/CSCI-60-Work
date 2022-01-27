/*
* Author: Tushar Shrivastav
* File Name: dSet.cpp
* Course: CSCI 60
*/

#include <iostream>
#include "dSet.h"
#include "dUSet.h"
#include "dynamicbag.h"

dSet::dSet() : dUSet(){}

dSet::dSet(DynamicBag& b) : dUSet(b){
  //sort b(Dynamic Bag) in ascending order
  //duplicates are already removed thanks dUSet(b) call

  for(std::size_t i = 0; i < (this->size())-1; i++){
    for(std::size_t j = i+1; j < (this->size()); j++){
      if(((*this)[i]) > ((*this)[j])){ //swap vars if greater
        int tmp = (*this)[i];
        int tmp2 = (*this)[j];
        //erase both spots
        DynamicBag::erase_one(tmp);
        DynamicBag::erase_one(tmp2);
        //insert back but swap spots
        DynamicBag::insertAt(tmp2, i);
        DynamicBag::insertAt(tmp, i+1);
      }
    }
  }

}

void dSet::insert(int target){
  //erase potential duplicates
  erase(target);
  //insert target val
  int idx = 0;
  //since it is already sorted we can iterate to target val
  for(int i = 0; i < target ; i++){
      if(count(i) != 0) //checking until target and incrimenting incrementing
        idx++;         //finds final index target should be placed at
  }
  //insert target at appropriate index
  insertAt(target, idx);
}
