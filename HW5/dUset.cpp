/*
* Author: Tushar Shrivastav
* File Name: dUSet.cpp
* Course: CSCI 60
*/

#include <iostream>
#include "dUSet.h"
#include "dynamicbag.h"

dUSet::dUSet() : DynamicBag(){}

dUSet::dUSet(DynamicBag& b) : DynamicBag(b){
  //check for duplicates and erase them
  for(int i = 0; i < b.size()-1; i++){
    for(int j = i + 1; j < b.size(); j++){
      if(b[i] == b[j])
        erase_one(b[i]);
    }
  }
}

void dUSet::insert(int target){
  //erase potential duplicates
  erase(target);
  //insert target val
  DynamicBag::insert(target);
}
