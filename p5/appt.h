#ifndef APPT_H
#define	APPT_H
// Author: Sean Davis
#include "time.h"

using namespace std;

class Appointment
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;
  static int count;
public:
  Appointment();
  Appointment(const Appointment &appt);
  ~Appointment();
  void addAppointment();
  bool operator==(const char *subject2)const;
  static int getCount();
  bool operator<(const Appointment &appointment2) const;
  friend ostream & operator<<(ostream & os, const Appointment &appointment);
  friend istream & operator>>(istream & in, Appointment &appointment);

}; // class Appoiintmen
#endif	// APPT_H 

