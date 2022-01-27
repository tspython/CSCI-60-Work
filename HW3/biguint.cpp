#include <iostream>
#include "biguint.h"
#include <string>
//constructors
biguint::biguint(){
  for(std::size_t i = 0 ; i < CAPACITY; i++){
    data_[i] = 0;
  }
}

biguint::biguint(const std::string s){
  for(std::size_t i=0; i < CAPACITY; i++){
    data_[i] = 0;
  }

  for(std::size_t i = 0; i < s.length(); i++){
    if(s[i] != 0){
      data_[i] = s[s.length()-i-1] - '0';
    }
  }
}

unsigned short biguint::operator [](std::size_t pos) const{
  if(pos >= CAPACITY)
    return 0;
  return data_[pos];
}

std::ostream& operator <<(std::ostream& out, const biguint& b){
  for(std::size_t i = 0; i < 20; i++){
    out<<b[20-1-i];
  }
  return out;
}

void biguint::operator += (const biguint & b){

  int carryOver = 0;

  for(std::size_t i = 0; i < CAPACITY; i++){
    int added = data_[i] + b[i] + carryOver;
    carryOver = 0;
    if (added > 9){
      carryOver++;
      data_[i] = added % 10;
    } else{
      data_[i] =  added;
    }
  }
}

void biguint::operator -= (const biguint & b){
  for(std::size_t i = 0; i<CAPACITY; i++){
    if((i==CAPACITY -1 ) && (data_[i] - b[i] < 0)){
      for (int j = 0; j < CAPACITY; j++)
        data_[j] = 0;
      return;
    }
    if(data_[i] < b[i]){
      data_[i] = data_[i] + 10 - b[i];
      data_[i+1] -= 1;
    }
    else{
      data_[i] -= b[i];
    }
  }
}

bool biguint::divisible_by_9() const{
  std::size_t sum = 0;
  for(std::size_t i = 0; i < CAPACITY; i++)
    sum+=data_[i];
  return (sum%9 ==0);
}

biguint operator + (const biguint &a, const biguint &b){
  biguint c = a;
  c+=b;
  return c;
}

biguint operator - (const biguint &a, const biguint &b){
  biguint c = a;
  c-=b;

  return c;
}

int biguint::compare(const biguint & b) const{
  for(int i = CAPACITY - 1; i>=0; i-- ){
    if (data_[i] > b[i])
      return 1;
    if(data_[i] < b[i])
      return -1;
  }
  return 0;
}

bool operator < (const biguint &a, const biguint &b){
  if(a.compare(b) == -1)
    return true;
  return false;
}
bool operator <= (const biguint &a, const biguint &b){
  if(a.compare(b) == -1 || a.compare(b) == 0)
    return true;
  return false;
}
bool operator != (const biguint &a, const biguint &b){
  if(a.compare(b) != 0)
    return true;
  return false;
}
bool operator == (const biguint &a, const biguint &b){
  if(a.compare(b) == 0)
    return true;
  return false;
}
bool operator >= (const biguint &a, const biguint &b){
  if(a.compare(b) == 1 || a.compare(b) == 0)
    return true;
  return false;
}
bool operator > (const biguint &a, const biguint &b){
  if(a.compare(b) == 1)
    return true;
  return false;
}

std::string biguint::to_string(){
  std::string str = "";
  for(std::size_t i = 0; i < CAPACITY; i++){
    str+=data_[CAPACITY-1-i] + '0';
  }
  return str;
}
