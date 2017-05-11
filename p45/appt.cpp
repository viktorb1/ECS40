// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include <string.h>
#include "appt.h"
#include "time.h"

using namespace std;

int Appointment::count = 0;


Appointment::Appointment() : subject(NULL), location(NULL)
{
  count++;
} // Appointment() default constructor


Appointment::Appointment(Time start, Time end, char *sub, char *loc) : 
  startTime(start),
  endTime(end)
{
  subject = new char[strlen(sub) + 1];
  location = new char[strlen(loc) + 1];
  strcpy(subject, sub);
  strcpy(location, loc);
  count++;
}  // Appointment() standard constructor


Appointment::Appointment(const Appointment& appt) : 
  startTime(appt.startTime),
  endTime(appt.endTime),
  subject(NULL),
  location(NULL)
{
  if (appt.subject)
  {
    subject = new char[strlen(appt.subject) + 1];
    strcpy(subject, appt.subject);
  } // if subject is set to something in the appt that we're trying to copy

  if (appt.location)
  {
    location = new char[strlen(appt.location) + 1];
    strcpy(location, appt.location);
  } // if location is set to something in the appt that we're trying to copy
} // Appointment() copy constructor


Appointment::~Appointment()
{
  delete [] subject;
  delete [] location;
}  // destroy()


bool Appointment::equal(const char *subject2)const
{
  return strstr(subject, subject2) != NULL;
}  // equal()


bool Appointment::lessThan(const Appointment *appointment2) const
{
  return startTime.lessThan(&appointment2->startTime); 
}  // lessThan()


void Appointment::print() const
{
  startTime.print();
  endTime.print();
  cout << left << setw(13) << subject << location << right << endl;
} // print()


void Appointment::read()
{
  char *ptr;
  ptr = strtok(NULL, ",");
  subject = new char[strlen(ptr) + 1];
  strcpy(subject, ptr);
  startTime.read();
  endTime.read();
  ptr = strtok(NULL, "\n");
  location = new char[strlen(ptr) + 1];
  strcpy(location, ptr);
} // read()


int Appointment::getCount()
{
  return count;
} // getCount()