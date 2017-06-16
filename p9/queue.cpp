#include <stdexcept>
#include <iostream>
#include <cassert>


Whoops::Whoops(const string &messag) : message(messag)
{
} // Whoops() constructor


const string& Whoops::what() const
{
  return message;
} // what()


template <typename T>
Queue<T>::Queue(int siz) : count(0), size(siz), front(0), back(0)
{
  assert(size >= 0);

  try
  {
    if (size < 0)
      throw bad_alloc();
    
    queueVector = new T[siz];
  } // check if size is less than 0
  catch(const bad_alloc &ba)
  {
    cout << ba.what() << " ";
  } // print message if size is 
} // Queue() constructor


template <typename T>
Queue<T>::~Queue()
{
  if (size > 0)
    delete []queueVector;
} // ~Queue() destructor


template <typename T>
void Queue<T>::push(const T &value)
{
  assert (count < size);

  if (count >= size)
    throw Whoops("Queue overflow error.");

  queueVector[back++] = value;
  back %= size;
  count++;
} // push()


template <typename T>
void Queue<T>::pop(T &value)
{
  assert(count > 0);

  if (count <= 0)
    throw out_of_range("Queue underflow error.");

  value = queueVector[front++];
  front %= size;
  count--;
} // pop()