#include <stdexcept>
#include <iostream>
#include <cassert>


template <typename T>
void Stack<T>::push(const T &value)
{
  stackList.push_back(value);
} // push()


template <typename T>
void Stack<T>::pop(T &value)
{
  assert(! stackList.empty());

  if (stackList.empty())
    throw out_of_range("Stack underflow error.");

  value = stackList.back();
  stackList.pop_back();
} // pop()