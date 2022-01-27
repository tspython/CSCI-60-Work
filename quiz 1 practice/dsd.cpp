#include <iostream>
#include <string>

class SdCard{
  private:
    string name;
    int capacity;
    int memory_used;
  public:
    SdCard();
    SdCard(string n, int c, int mu);

  string get_name(){
    return name;
  }

  int get_capacity(){
    return capacity;
  }

  int get_memory_used(){
    return memory_used;
  }

  bool takePicture();
  void empty();
  bool dump(SdCard& sd);
};


SdCard::SdCard(){
  name = "";
  capacity = 0;
  memory_used = 0;
}

  SdCard::SdCard(string n, int c, int mu){
  name = n;
  capacity = c;
  memory_used = mu;
}

bool SdCard::takePicture(){
  if(c == mu)
    return false;
  memory_used += 50;
  return true;
}

void SdCard::empty(){
  memory_used = 0;
}

bool SdCard::dump(SdCard& sd){
  if(sd.get_memory_used() + memory_used > capacity)
    return false;
  memory_used += sd.get_memory_used();
  sd.empty();
  return true;
}
