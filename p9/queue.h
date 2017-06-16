#ifndef _QUEUE_H
#define _QUEUE_H


template <typename T>
class Queue
{
  T *queueVector;
  int count, size, front, back;
public:
  Queue(int size);
  ~Queue();
  void pop(T &value);
  void push(const T &value);
}; // class Queue


class Whoops
{
  const string message;
public:
  Whoops(const string &message);
  const string& what() const;
}; // class Whoops


#include "queue.cpp"

#endif