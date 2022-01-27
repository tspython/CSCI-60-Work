#include <iostream>
#include "dbiguint.h"
#include <string>
//constructors
dbiguint::dbiguint(){
  capacity_ = 1;
  data_ = new unsigned short[capacity_];
  data_[0] = 0;
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
  return capacity_; // size is capacity
}

unsigned short dbiguint::operator [](std::size_t pos) const{
  if(pos >= capacity_) //initial condition
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
    unsigned short* tmp = new unsigned short [newcapacity];
    for(std::size_t i = 0; i < newcapacity; i++)
      tmp[i] = data_[i];
    delete [] data_;
    data_ = tmp;
    capacity_ = newcapacity;
    //return; // do nothing if new capacity is < than current capacity_
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
  //check if is already same
  if(this==&b)
    return;
  //deep copy method
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
  std::string str; //using string from cmnd line
  out >> str;
  b = dbiguint(str); // ^^^^^^^^^ (above)
                    // to re-construct b with new string
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
  int j = 0;
  //return dbiguint with no 0s
  for(std::size_t i = 0; i < capacity_; i++){
    if((data_[capacity_-1-i]) == 0 && (capacity_-1-i > 0) ){
      j++;
    }
    else
      break;
  }
  reserve(capacity_ - j);
}

dbiguint operator - (const dbiguint &a, const dbiguint &b){
  dbiguint c;
  c = a;
  c-=b;
  return c;
}

dbiguint operator + (const dbiguint &a, const dbiguint &b){
  dbiguint c;
  c = a;
  c+=b;
  return c;
}

void dbiguint::operator *=(const dbiguint & b){
  dbiguint bigger;
  dbiguint smaller;
  //check if this dbiguint is longer or b is longer
  if(compare(b) == 1){
    //bigger to this biguint
    bigger = *this;
    smaller = b;
  }
  else if(compare(b) == -1){
    bigger = b;
    //set smaller to to this Biguint
    smaller = *this;
  }
  else{ // since it is the same it doesn't matter which is which
    bigger = b;
    smaller = *this;
  }
  //loop in smaller func
    //loop w bigger func
        //multiply all upper digits by last digit of smaller num
  unsigned short* tmp = new unsigned short [capacity_ + b.size()];
  int k = 0;
    for(std::size_t i = 0; i < smaller.size(); i++){
      k=i; // need this variable to shift the multiplication
            // as when we multiply by hand we add a 0 after every iteration
      for(std::size_t j = 0; j < bigger.size(); j++){
        tmp[k] = smaller[i] * bigger[j] + tmp[k];
        tmp[k+1] = tmp[k+1] + tmp[k]/10; // carry over to next item
        tmp[k] = tmp[k]%10; // keep single digit in current slot
        k++;
      }
    }
  delete [] data_;
  data_ = tmp;
  capacity_ += b.size();

  //deleting leading zeroes in this dbiguint
  int j = 0;
  for(std::size_t i = 0; i < capacity_; i++){
    if((data_[capacity_-1-i]) == 0 && (capacity_-1-i > 0) ){
      j++;
    }
    else
      break;
  }
  reserve(capacity_ - j);
  // end of leading 0's deletion
}

dbiguint operator * (const dbiguint &a, const dbiguint &b){
  dbiguint c;
  c = a;
  c*=b;
  return c;
}
