// Author: Sean Davis
#include "appt.h"
#include <iostream>

template <class T>
ListNode<T>::ListNode(T appt, ListNode<T> *n) : appointment(appt), next(n)
{
}  // ListNode();


template <class T>
ListNode<T>::~ListNode()
{
  delete appointment;
}  // ListNode();


template <class T>
LinkedList<T>::LinkedList() : head(NULL)
{
} // LinkedList()


template <class T>
LinkedList<T>::~LinkedList() 
{
  for(ListNode<T> *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }   // for each ListNode
} // ~LinkedList()


template <class T>
const T LinkedList<T>::find(const char* subject) const
{
  static ListNode<T> *ptr = NULL;
  
  if(!ptr)
    ptr = head;
  else // had found a match previously, and are in the middle of list
    ptr = ptr->next;
  
  for( ; ptr; ptr = ptr->next)
   if(*ptr->appointment == subject)
     return ptr->appointment;

  return NULL;
}  // find()
 

template <class T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList &rhs)
{
  ListNode<T> *ptr2 = NULL;
  
  if(this == &rhs)
    return *this;
  
  for(ListNode<T> *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }   // for each ListNode
  
  for(ListNode<T> *ptr = rhs.head; ptr; ptr = ptr->next)
    if(ptr2)
      ptr2 = ptr2->next 
        = new ListNode<T>(ptr->appointment->clone(), NULL);
    else  // empty list
      ptr2 = head =  new ListNode<T>(ptr->appointment->clone(), NULL);
    
  return *this;
}  // operator=

template <class T>
const T LinkedList<T>::operator[] (int index) const
{
  int i;
  ListNode<T> *ptr;
  
  for(i = 0, ptr = head; ptr && i < index; i++, ptr = ptr->next);
  
  if(i == index && ptr)
    return ptr->appointment;
  else // not found
    return NULL;
} // const operator[]


template <class T>
LinkedList<T>& LinkedList<T>::operator+= (T appointment)
{
  ListNode<T> *ptr, *prev = NULL;
    
  for(ptr = head; ptr && *ptr->appointment < *appointment; ptr = ptr->next)
    prev = ptr;
  
  if(prev) 
    prev->next = new ListNode<T>(appointment, ptr);
  else  // inserting at front of list.
    head = new ListNode<T>(appointment, ptr);
  
  return *this;
}  // operator+=


template <class Y>
ostream& operator<< (ostream& os, const LinkedList<Y> &list)
{
  for(ListNode<Y> *ptr = list.head; ptr; ptr = ptr->next)
  {
    os << *ptr->appointment;
    os << endl;
  } // loop through list nodes and print them

  return os;
} // operator<<()


