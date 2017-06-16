#ifndef _STACK_H
#define _STACK_H

#include <list>
using namespace std;


template <typename T>
class Stack
{
  list<T> stackList;

public:
  void push(const T &value);
  void pop(T &value);
}; // class Stack


#include "stack.cpp"

#endif