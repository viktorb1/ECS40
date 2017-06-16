#ifndef APPT_H
#define	APPT_H
// Author: Sean Davis
#include <iostream>
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
  virtual ~Appointment();
  virtual Appointment* clone() const;
  virtual Appointment* read(istream &is);
  void addAppointment();
  bool operator== (const char *subject) const;
  static int getCount();
  bool operator< (const Appointment &appointment2) const;
  friend ostream& operator<< (ostream &os, const Appointment &appointment);
  friend istream& operator>> (istream &is, Appointment &appointment);
  virtual ostream& write(ostream &os) const;
}; // class Appoiintmen
#endif	// APPT_H 

