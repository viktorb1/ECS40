#include <iostream>
#include "appt.h"
#include "linkedlist.h"

using namespace std;

ListNode* currNode;

LinkedList::LinkedList() : head(NULL)
{
} // LinkedList

LinkedList& LinkedList::operator= (const LinkedList &rhs)
{
  ListNode *ptr, *tail = NULL;
  
  if(this == &rhs)
    return *this;

  for (ptr = head; ptr; ptr = head)//ptr->next)
  {
    head = ptr->next;
    delete ptr;
  } // for node

  tail = head;
  
  for (ptr = rhs.head; ptr; ptr = ptr->next)
  {
    Appointment *appt = new Appointment(*(ptr->appointment));
    
    if (!tail)
    {
      tail = new ListNode(appt, NULL);
      head = tail;
    } // if list is empty

    else // if there are nodes
    {
      tail->next = new ListNode(appt, NULL);
      tail = tail->next;
    } // if there exist nodes

  } // for right hand side

  return *this;
} // operator=

const Appointment* LinkedList::operator[](int index) const
{
  ListNode* ptr;
  int count = 0;

  for (ptr = head; ptr; ptr = ptr->next)
  {
    if (ptr && count == index)
      break;
    count++;
  } // for node

  return ptr->appointment;
} // operator[]


Appointment*& LinkedList::operator[](int index)
{
  ListNode *ptr = head, *prev = NULL;
  int count = 0;
  
  while(ptr)
  {
    if (ptr && count == index)
      return ptr->appointment;
    count++;
    prev = ptr;
    ptr = ptr->next;
  } // while ptr

  if (!prev)
  {
    Appointment *appt = new Appointment();
    head = new ListNode(appt, NULL);
    return head->appointment;
  } // if prev is NULL

  else // insert in head
  {
    Appointment *appt = new Appointment();
    prev->next = new ListNode(appt, NULL);
    return prev->next->appointment;
  } // insert node in head

} // operator[]


LinkedList& LinkedList::operator+=(Appointment *appt)
{
  ListNode *ptr, *prev = NULL;
  
  for (ptr = head; 
    ptr && *ptr->appointment < *appt; ptr = ptr->next)   
      prev = ptr;
    
    if (!prev)
    {
        //Appointment *appt = new Appointment();
      head = new ListNode(appt, ptr); 
    } // if prev NULL

    else // insert in head
    {
      //Appointment *appt = new Appointment();
      prev->next = new ListNode(appt, ptr);
    } // insert in head

  return *this;
} // operator+=

ostream & operator<<(ostream & os, const LinkedList & LinkedList)
{
  ListNode *ptr;
  
  for (ptr = LinkedList.head; ptr; ptr = ptr->next)
    os << *ptr->appointment;
  
  return os;
} // operator<<



Appointment* LinkedList::find(const char* subject) const
{
  static ListNode* currnode = NULL;
  ListNode *ptr = head;

  if (currnode)
    ptr = currnode->next;

  for (; ptr; ptr = ptr->next)
    if (*ptr->appointment == subject)
      break;

  currnode = ptr;

  if(currnode)
    return ptr->appointment;

  return NULL;
} // find



ListNode::~ListNode()
{
  delete appointment;
 // delete next;
} // ~ListNode()


LinkedList::~LinkedList()
{
  ListNode *ptr;

  for (ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  } // for node in list

}  // ~LinkedList()



