#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
public:
    // CONSTANTS & TYPES

    static const std::size_t CAPACITY = 20;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint();

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(const std::string s);

    // CONSTANT MEMBER FUNCTIONS

    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator [](std::size_t pos) const;

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(const biguint & b) const;



    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator += (const biguint & b);
    /*
    * Pre: none
    * Post:b is subtracted to this biguint;
    */
    void operator -= (const biguint & b);
    /*
    * Pre: none
    * Post: returns string with all digits of this biguint;
    */
    std::string to_string();

    // pre: none
    // post: returns true if and only if this biguint is divisible by 9
    bool divisible_by_9() const; 

private:

    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions
/*
* Pre: none
* Post: overloads << operator to output b to out
*/
std::ostream& operator <<(std::ostream& out, const biguint& b);
/*
* Pre: none
* Post: returns sum of two biguints
*/
biguint operator + (const biguint &, const biguint &);
/*
* Pre: none
* Post: returns difference of two biguints
*/
biguint operator - (const biguint &, const biguint &);
/*
* Pre: none
* Post: returns true if compare returns -1 else false
*/
bool operator < (const biguint &, const biguint &);
/*
* Pre: none
* Post: returns true if compare returns 0 or -1 else false
*/
bool operator <= (const biguint &, const biguint &);
/*
* Pre: none
* Post: returns true if compare is not 0 else false
*/
bool operator != (const biguint &, const biguint &);
/*
* Pre: none
* Post: returns true if compare is 0 else false
*/
bool operator == (const biguint &, const biguint &);
/*
* Pre: none
* Post: returns true if compare is 1 or 0 else false
*/
bool operator >= (const biguint &, const biguint &);
/*
* Pre: none
* Post: returns true if compare is 1 else false
*/
bool operator > (const biguint &, const biguint &);





#endif // BIGUINT_H
