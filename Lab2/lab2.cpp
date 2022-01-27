#include <iostream>
#include <string>
using namespace std;


class ModInt{
  private:
    int mod_;
    int num_;
  public:
    ModInt(){
      mod_ = 0;
      num_ = 0;
    }
    ModInt(int m, int n){
      mod_ = m;
      num_ = n;
    }

    int mod(){return mod_;}
    int num(){return num_;}

    /*
    * Pre: takes in mod object
    * Post: overloads += operator to add nums of two ModInts together if same mod
    *       if not, set mod_ = -1 and num_ to = -1
    */
    void operator +=(ModInt rhs);
};

void ModInt::operator +=(ModInt rhs){
  if(mod_ == rhs.mod_)
  {
    num_ += rhs.num_;
    num_ = num_ % mod_;
  }
  else
  {
    mod_ = -1;
    num_ = -1;
  }
}

/*
* Pre: takes in two mod objects
* Post: returns true if both mod and num are equal for both objects
*/
bool operator ==(ModInt lhs, ModInt rhs){
  if(lhs.mod() == rhs.mod() && lhs.num() == rhs.num())
    return true;
  return false;
}

/*
* Pre: takes in two ModInt Objects
* Post: overloads + operator to add two ModInt Objects if same mod
*       otherwise return ModInt object with num_ = -1 and mod_ = -1
*/
ModInt operator +(ModInt lhs, ModInt rhs){
  //ModInt combined;
  if(lhs.mod() == rhs.mod()){
    ModInt combined = ModInt(lhs.mod(), (lhs.num() + rhs.num()) % lhs.mod());
    return combined;
  }
  ModInt notCombinable = ModInt(-1,-1);
  return notCombinable;
}


int main(){
  ModInt one = ModInt(10, 10);
  ModInt two = ModInt(10, 10);
  ModInt three = ModInt(10, 8);
  ModInt four = ModInt(10, 5);
  ModInt empty;
  ModInt plus;
  //part 1
  cout << one.mod() << endl;
  cout << one.num() << endl;
  cout << empty.mod() << endl;
  cout << empty.num() << endl;
  //part 2
  bool x = one == two;
  cout << x << endl;
  // part 3
  three += four;
  cout << three.num() << endl;
  // part 5
  plus = two + four;
  cout << plus.num() << endl;

  return 0;
}
