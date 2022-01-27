//Make the file #include-able
#ifndef RATIONAL_H  //if not defined, matching endif at the end
#define RATIONAL_H  //then define
#include <iostream>
#include <cassert>
//ADT Style:  no using namespace std
class Rational{
public:
    Rational(int n, int d);
    Rational();

    int numer(){  return numer_; }//ADT Style:give the getter the variable name minus the _
    int denom(){  return denom_; }

    //pre:  d cannot be 0
    //post:  denom_ is updated to the value passed in.
    void set_denom(int d);

    //pre: none
    //post: modifies the numer_ and denom_ to reflect the result
    //of multiplying this Rational and the Rational passed in.
    //the denominator will be the product
    //of the denominators of the operands, will be reduced after.
    void operator *=(Rational b);

    //pre: none
    //post: modifies the numer_ and denom_ to reflect the result
    //of multiplying this Rational and the Rational passed in.
    //the denominator will be the product
    //of the denominators of the operands, will be reduced after.
    void operator +=(Rational b);

    /*
    * Pre: none
    * Post: calls gcd function and divides numer and denom by them giving
    *       a simplified radical
    */
    void reduce();
    /*
    * Pre: pass in numerator and denominator
    * Post: return greatest common divisor between them
    *
    */
    int greatest_common_divisor(int n, int d);

  private:
      int numer_;//ADT Style: trailing _ means this is a private variable
      int denom_;
};
std::ostream& operator <<(std::ostream& out, Rational r);//Need the std:: because we aren't using the standard namespace
//pre: none
//post: returns a Rational that is the result of adding the
//two Rational parameters
//the denominator will be the product
//of the denominators of the operands, will be reduced after.
Rational operator +(Rational a, Rational b);

//pre: none
//post: returns a Rational that is the result of multiplying the
//two Rational parameters
//the denominator will be the product
//of the denominators of the operands, will be reduced after.
Rational operator *(Rational a, Rational b);

/*
* Pre: pass in two rational objects
* Post: returns true if they are equal, else return false
*/
bool operator ==(Rational lhs, Rational rhs);

#endif
