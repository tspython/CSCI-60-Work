#include <iostream>
#include "dbiguint.h"
#include <string>
//constructors
dbiguint::dbiguint(){
    capacity_ = 0;
    data_ = nullptr;
}


dbiguint::dbiguint(const std::string & s){
  capacity_ = s.length();
  data_ = new unsigned short[capacity_];

  for(std::size_t i = 0; i < capacity_; i++){
    if(s[i] != 0){
      data_[i] = s[s.length()-i-1] - '0';
    }
  }
}

std::size_t dbiguint::size() const{
  return capacity_;
}

unsigned short dbiguint::operator [](std::size_t pos) const{
  if(pos >= capacity_)
    return 0;
  return data_[pos];
}

std::ostream& operator <<(std::ostream& out, const dbiguint& b){
  for(std::size_t i = 0; i < b.size(); i++){
    out<<b[b.size()-1-i];
  }
  return out;
}

void dbiguint::reserve(std::size_t newcapacity){
  if(newcapacity>capacity_){

    std::size_t tempcapacity = capacity_;
    capacity_ = newcapacity;
    unsigned short* temp = new unsigned short [capacity_];

    for (std::size_t i = 0; i < capacity_; i++){
      temp[i] = data_[i];
    }

    for(std::size_t i = tempcapacity; i < capacity_; i++){
      temp[i] = 0;
    }

    delete [] data_;
    data_ = temp;
  }
  else{
    // reduce memory allocated to data

    return; // do nothing if new capacity is < than current capacity_
  }
}

void dbiguint::operator += (const dbiguint & b){

  int carryOver = 0;

  for(std::size_t i = 0; i < capacity_; i++){
    if(b.size()>capacity_)
      reserve(b.size());
    int added = data_[i] + b[i] + carryOver;
    carryOver = 0;
    if((added > 9) && (i == capacity_ - 1)){
      reserve(capacity_ + 1);
      carryOver++;
      data_[i] = added % 10;
    }
    else if (added > 9){
      carryOver++;
      data_[i] = added % 10;
    }
    else{
      data_[i] =  added;
    }
  }
}

void dbiguint::operator =(const dbiguint & b){
  if(this==&b)
    return;
  delete [] data_;
  capacity_ = b.size();
  data_ = new unsigned short[capacity_];
  for(std::size_t i = 0; i < capacity_; i++)
    data_[i] = b[i];
}

int dbiguint::compare(const dbiguint & b) const{
  for(int i = capacity_ - 1; i>=0; i-- ){
    if (data_[i] > b[i])
      return 1;
    if(data_[i] < b[i])
      return -1;
  }
  return 0;
}

bool operator < (const dbiguint &a, const dbiguint &b){
  if(a.compare(b) == -1)
    return true;
  return false;
}
bool operator <= (const dbiguint &a, const dbiguint &b){
  if(a.compare(b) == -1 || a.compare(b) == 0)
    return true;
  return false;
}
bool operator != (const dbiguint &a, const dbiguint &b){
  if(a.compare(b) != 0)
    return true;
  return false;
}
bool operator == (const dbiguint &a, const dbiguint &b){
  if(a.compare(b) == 0)
    return true;
  return false;
}
bool operator >= (const dbiguint &a, const dbiguint &b){
  if(a.compare(b) == 1 || a.compare(b) == 0)
    return true;
  return false;
}
bool operator > (const dbiguint &a, const dbiguint &b){
  if(a.compare(b) == 1)
    return true;
  return false;
}

std::istream & operator >> (std::istream & out, dbiguint & b){
  std::string str;
  out >> str;
  b = dbiguint(str);
  return out;
}

void dbiguint::operator -= (const dbiguint & b){
  for(std::size_t i = 0; i<capacity_; i++){
    if((i==capacity_ -1 ) && (data_[i] - b[i] < 0)){
      for (int j = 0; j < capacity_; j++)
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
dbiguint operator + (const dbiguint &a, const dbiguint &b){
  dbiguint c = a;
  c+=b;
  return c;
}
