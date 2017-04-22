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

public:
  void destroy();
  bool equal(char *subject);
  bool lessThan(Appointment *appointment2);
  void print();
  void read();
}; // Appointment

#endif	// APPT_H 

