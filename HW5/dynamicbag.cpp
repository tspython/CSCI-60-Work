#include "dynamicbag.h"

DynamicBag::DynamicBag(){
  capacity_=0;
  used_ = 0;
  data_ = nullptr;//nullptr is our concept of pointing at nothing
}

//data_, capacity_, used_ must be initialized here
DynamicBag::DynamicBag(int arr[], std::size_t size){
  used_ = size;
  capacity_ = 2*size;
  data_ = new int[capacity_];

  for(std::size_t i = 0; i<used_; ++i){
    data_[i] = arr[i];
  }
}
//This should make a deep copy
DynamicBag::DynamicBag(const DynamicBag &b){
  capacity_ = b.size();
  used_ = b.size();
  data_ = new int[capacity_];
  for(std::size_t i = 0; i<used_; ++i){
    data_[i] = b[i];
  }

}
void DynamicBag::operator =(const DynamicBag &b){
  if(this==&b)
    return;
  delete []data_;
  capacity_ = b.size();
  used_ = b.size();
  data_ = new int[capacity_];
  for(std::size_t i = 0; i<used_; ++i){
    data_[i] = b[i];
  }
  /*All of these do the same thing
  size();
  (*this).size();
  this->size();
*/
}
DynamicBag::~DynamicBag(){
  delete [] data_;
}
int DynamicBag::operator [](std::size_t pos) const{
  assert(pos<used_);
  return data_[pos];
}
std::size_t DynamicBag::count(int target) const{
  std::size_t count = 0;
  for(std::size_t i=0; i<used_; ++i){
    if(data_[i]==target)
      ++count;
  }
  return count;
}

void DynamicBag::insert(int target){
    if(size()<capacity_){
    data_[used_] = target;
    used_++;
  }else{
    size_type newcap;
    if(capacity_>0)
      newcap = 2*capacity_;
    else
    newcap = 1;
    int * p2 = new int[newcap];//We copied this from our previous example and modified it.
    for(int i=0; i<used_; ++i){
      p2[i] = data_[i];
    }
    delete [] data_;
    data_ = p2;
    data_[used_] = target;
    ++used_;

    capacity_ = newcap;
    p2 = nullptr;
  }
}

void DynamicBag::insertAt(int item, size_type index){
  if(capacity_==used_){
    size_type newcap;
    if(capacity_>0)
      newcap = 2*capacity_;
    else
      newcap = 1;
    int* temp = new int[newcap];
    for(size_type i = 0; i<index; ++i)
      temp[i] = data_[i];
    temp[index] = item;
    for(size_type i = index+1; i<used_+1; ++i)
        temp[i] = data_[i-1];
    delete [] data_;
    data_ = temp;
    capacity_ = newcap;
  }
  else{
    for(size_type i = used_; i>index; --i){
        data_[i] = data_[i-1];
    }
    data_[index] = item;
  }
  used_++;
}


void DynamicBag::operator += (const DynamicBag & b){

  for(std::size_t i=0; i< b.size(); ++i){
      insert(b[i]);
  }
}

bool DynamicBag::erase_one(int target){
  std::size_t marker = -1;
  for(std::size_t i= 0; i<used_ && marker==-1; ++i){
    if(data_[i] == target)
      marker = i;
  }
  if(marker==-1){
    return false;
  }

  for(std::size_t i = marker; i<used_-1; ++i){
    data_[i] = data_[i+1];
  }
  --used_;
  if((used_)<capacity_/4){
    capacity_/=2;
  }
  int* temp = new int[capacity_];
  for(std::size_t i= 0; i<used_; ++i){
    temp[i] = data_[i];
  }
  delete [] data_;
  data_ = temp;

  return true;
}


std::size_t DynamicBag::erase(int target){
  std::size_t count = 0;
  while(erase_one(target)){
    ++count;
  }
  return count;
}

DynamicBag operator + (const DynamicBag & b1, const DynamicBag & b2){
  DynamicBag b;
  b+=b1;
  b+=b2;
  return b;
}

std::ostream& operator<<(std::ostream&  out, const DynamicBag& b){
  for(std::size_t i = 0; i<b.size(); ++i)
    out<<b[i]<<" ";
  return out;
}
