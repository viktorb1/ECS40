#ifndef VECTOR_H
#define VECTOR_H

template <class T> 
class Vector
{
  T *array;
  int count, size;
  
public:
  Vector(int initsize);
  ~Vector();
  int getCount() const;
  const T& operator[](int index) const;
  T& operator[](int index);
  int operator+=(const T &object);
  
}; // class Vector

#include "vector.cpp"

#endif // VECTOR_H