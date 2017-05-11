#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "appt.h"

class LinkedList;

using namespace std;

class ListNode
{
  Appointment *appointment;
  ListNode *next;
  ListNode(Appointment *appt, ListNode* n):appointment(appt), next(n){}
  friend class LinkedList;
  friend ostream & operator<<(ostream & os, const LinkedList & LinkedList);
  ~ListNode();
}; // class ListNode

class LinkedList
{
  ListNode *head;
public:
  LinkedList & operator=(const LinkedList &rhs);
  const Appointment* operator[](int index) const;
  LinkedList & operator+=(Appointment *appointment);
  Appointment*& operator[](int index); 
  LinkedList();
  friend ostream & operator<<(ostream & os, const LinkedList & LinkedList);
  Appointment* find(const char* subject) const;
  Appointment* findlast(const char* subject) const;
  ~LinkedList();
}; // class List


#endif
