#ifndef NDIMENSIONPOINT_H
#define NDIMENSIONPOINT_H
#include <iostream>
#include <complex>
#include <string>

template <typename T>
class n_dimension_point{
  private:
    T arr[10];
    int dimension;
  public:
    //constructors
    n_dimension_point();

    n_dimension_point(int d);

    n_dimension_point(T a[], int d);

    /*
    * pre: none
    * post: copies p to this point
    */
    void operator =(const n_dimension_point p);
    /*
    * pre: none
    * post: adds p to this point
    */
    void operator +=(n_dimension_point p);

    //getter
    int getSize(){
      return dimension;
    }
    T getItem(int i){
      return arr[i];
    }

};

template <typename T>
n_dimension_point<T>::n_dimension_point(){
  dimension = 0;
  T t = T();
  arr[0] = t;
}

template <typename T>
n_dimension_point<T>::n_dimension_point(int d){
  dimension = d;
  T t = T();
  for (int i = 0; i < d; i++){
    arr[i] = t;
  }
}

template <typename T>
n_dimension_point<T>::n_dimension_point(T a[], int d){
  dimension = d;
  for (int i = 0; i < d; i++){
    arr[i] = a[i];
  }
}

template <typename T>
void n_dimension_point<T>::operator =(n_dimension_point p){
  dimension = p.getSize();
  for(int i = 0; i < p.getSize(); i++){
    arr[i] = p.getItem(i); // needs to support assignment operator
  }
}

template <typename T>
void n_dimension_point<T>::operator +=(n_dimension_point p){
  //find smaller array
  int sm = 0;
  if(p.getSize() > dimension)
    sm =1;
  //based on which one is smaller we perform the addition
  if(sm == 1){
    for(int i = 0; i < dimension; i++){
      arr[i]+=p.getItem(i); //needs to support += operator
    }
  }else{
    for(int i = 0; i < p.getSize(); i++){
      arr[i]+=p.getItem(i);
    }
  }
}

/*
* Pre: none
* Post: returns added result of two points
*/
template <typename T>
n_dimension_point<T> operator +(n_dimension_point<T> pa, n_dimension_point<T> pb){
  n_dimension_point<T> tmp;
  tmp = pa;
  tmp +=pb;
  return tmp;
}

/*
* pre: none
* post: true or false depending on if every item and dimension are equal
*/
template <typename T>
operator ==(n_dimension_point<T> pa, n_dimension_point<T> pb){ //T needs to support != operator
  if(pa.getSize() != pb.getSize())
    return false;
  for(int i = 0; i < pa.getSize(); i++){
    if(pa.getItem(i) != pb.getItem(i))
      return false;
  }
  return true;
}

#endif //NDIMENSIONPOINT_H
