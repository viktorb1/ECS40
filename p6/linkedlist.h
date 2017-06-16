#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <iostream>
#include "appt.h"

template <class T>
class LinkedList;

template <class T>
class ListNode
{
  T appointment;
  ListNode<T> *next;
  ListNode(T appt, ListNode<T> *n);
  ~ListNode();
  friend class LinkedList<T>;
  template <class Y>
  friend ostream& operator<< (ostream& os, const LinkedList<Y> &list);
};  // class ListNode


template <class T>
class LinkedList 
{
  ListNode<T> *head;
public:
  LinkedList();
  ~LinkedList();
  const T find(const char* subject) const;
  LinkedList<T>& operator= (const LinkedList<T> &rhs);
  const T operator[] (int index) const;
  T& operator[] (int index);
  LinkedList<T>& operator+= (T appointment);
  template <class Y>
  friend ostream& operator<< (ostream& os, const LinkedList<Y> &list);
  
}; // class linkedlist 

#include "linkedlist.cpp"

#endif	// LINKEDLIST_H

