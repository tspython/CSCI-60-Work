#include "Rational.h"

//prototypes
Rational::Rational(int n, int d){
  numer_ = n;
  denom_ = d;
}
Rational::Rational(){
  numer_ = 0;
  denom_ = 1;
}

void Rational::set_denom(int d){
  assert(d!=0);
  denom_ = d;
}


void Rational::operator *=(Rational b){
  numer_ = (numer_*b.numer_);
  denom_ = (denom_*b.denom_);
  Rational n = Rational(numer_, denom_);
  n.reduce();
  numer_ = n.numer();
  denom_ = n.denom();
}


void Rational::operator +=(Rational b){
  numer_ = (numer_*b.denom_)+(b.numer_*denom_);
  denom_ = (denom_*b.denom_);
  Rational n = Rational(numer_, denom_);
  n.reduce();
  numer_ = n.numer();
  denom_ = n.denom();
}

std::ostream& operator <<(std::ostream& out, Rational r){
  out<<r.numer()<<"/"<<r.denom();
  return out;
}

Rational operator +(Rational a, Rational b){
  Rational ans = Rational(0,1);
  ans+=a;
  ans+=b;
  ans.reduce();
  return ans;
}

Rational operator *(Rational a, Rational b){

    Rational ans = Rational(1, 1);
    ans*=a;
    ans*=b;
    ans.reduce();
    return ans;

}

bool operator ==(Rational lhs, Rational rhs){
  Rational x = Rational(rhs.numer(), rhs.denom());
  Rational y = Rational(lhs.numer(), lhs.denom());
  x.reduce();
  y.reduce();
  if((y.numer() == x.numer()) && (x.denom() == y.denom()) )
    return true;
  return false;
}

void Rational::reduce(){
  //find greatest common divisor
  //divide numer and denom by gcd
  //find greatest common factor
  int gcd = greatest_common_divisor(numer_, denom_);
  numer_ /= gcd;
  denom_ /= gcd;
}

int Rational::greatest_common_divisor(int n, int d){
  if(d != 0)
    return greatest_common_divisor(d, n % d);
  else
    return n;
}
