#ifndef DBIGUINT_H
#define DBIGUINT_H

#include <cstdlib>
#include <string>
#include <iostream>

class dbiguint
{
public:
    // pre: none
    // post: creates a dynamic bigint value 0
    dbiguint();

    // pre: s[0], ..., s[s.size()-1] are digits
    // post: creates a dbiguint whose digits are given in s
    dbiguint(const std::string & s);
/*We aren't implementing this constructor yet
    // pre:  none    //NEW
    // post: copy constructor: creates a new dynamic bigint which is
    //                         a copy of given dynamic bigint
    dbiguint(const dbiguint & b);
*/

    // pre: none    //NEW
    // post: returns dynamically allocated memory to heap
    //~dbiguint();

    // pre: none    //NEW
    // post: makes this dynamic bigint a copy of given dynamic bigint
    void operator =(const dbiguint & b);

    // pre: none    //NEW
    // post: returns the size of the memory block of this dbiguint
    std::size_t size() const;

    // pre: none
    // post: returns the digit at given pos (0 if does not exist)
    //       pos 0 is the least significant (units) digit
    unsigned short operator [](std::size_t pos) const;

    // pre: none
    // post: returns 0 if this dbiguint equals given dbiguint
    //               1 if this dbiguint >      given dbiguint
    //              -1 otherwise
    int compare(const dbiguint & b) const;

    // pre: none
    // post: returns a string containing the digits and sign of this dbiguint
    std::string toStdString() const;

    // pre: none
    // post: adds/subtracts given dbiguint to this dbiguint
    void operator +=(const dbiguint & b);
    /*
    * Pre: none
    * Post:b is subtracted to this biguint;
    */
    void operator -=(const dbiguint & b);
    /*
    * Pre: none
    * Post:b is multiplied to this biguint;
    */
    void operator *=(const dbiguint & b);

    // pre: none
    // post: if newcapacity_ <= capacity_ then do nothing (cannot shrink)
    //       else allocate a new block with size newcapacity_
    //       copy existing digits and fill the rest with 0
    void reserve(std::size_t newcapacity);

private:
    unsigned short *data_;
    std::size_t capacity_;

    // INVARIANTS:
    //    data_ points to (has the address of) a dynamic array
    //    of capacity_ digits
    //    data_[0] = least significant (units) digits
    //    data_[k] = digit at position k (or 0 if not used)


};


// nonmember functions

/*
* Pre: none
* Post: returns sum of two dbiguints
*/
dbiguint operator +(const dbiguint & a, const dbiguint & b);
/*
* Pre: none
* Post: returns difference of two dbiguints
*/
dbiguint operator -(const dbiguint & a, const dbiguint & b);
/*
* Pre: none
* Post: multiples dbiguint a to dbiguint b
*/
dbiguint operator *(const dbiguint & a, const dbiguint & b);

/*
* Pre: none
* Post: returns true if compare returns -1 else false
*/
bool operator < (const dbiguint & a, const dbiguint & b);
/*
* Pre: none
* Post: returns true if compare returns 0 or -1 else false
*/
bool operator <= (const dbiguint & a, const dbiguint & b);
/*
* Pre: none
* Post: returns true if compare is 0 else false
*/
bool operator == (const dbiguint & a, const dbiguint & b);
/*
* Pre: none
* Post: returns true if compare is not 0 else false
*/
bool operator != (const dbiguint & a, const dbiguint & b);
/*
* Pre: none
* Post: returns true if compare is 1 or 0 else false
*/
bool operator >= (const dbiguint & a, const dbiguint & b);
/*
* Pre: none
* Post: returns true if compare is 1 else false
*/
bool operator > (const dbiguint & a, const dbiguint & b);

/*
* Pre: none
* Post: overloads << operator to output b to out
*/
std::ostream & operator << (std::ostream & out, const dbiguint & b);
/*
* Pre: none
* Post: overloads >> operator to input into b
*/
std::istream & operator >> (std::istream & out, dbiguint & b);





#endif // DBIGUINT_H
