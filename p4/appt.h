#ifndef APPT_H
#define	APPT_H
// Author: Sean Davis
#include "time.h"

class Appointment
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;
  static int count;
public:
  Appointment();
  Appointment(Time start, Time end, char* sub, char* loc);
  ~Appointment();
  Appointment(const Appointment& appt);
  bool equal(const char *subject) const;
  bool lessThan(const Appointment *appointment2) const;
  void print() const;
  void read();
  static int getCount();

}; // class Appointment
#endif	// APPT_H 

