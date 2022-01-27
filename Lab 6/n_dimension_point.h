#ifndef NDIMENSIONPOINT_H
#define NDIMENSIONPOINT_H
#include <iostream>

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

    void operator =(const n_dimension_point p);

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
    arr[i] = p.getItem(i);
  }
}

#endif //NDIMENSIONPOINT_H
