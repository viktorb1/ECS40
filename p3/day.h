#ifndef DAY_H
#define	DAY_H
// Author: Sean Davis
#include "appt.h"

class Day
{
  short day;
  short month;
  short year;
  Appointment *appts[8];
  short apptCount;

public:
  void create(int day1, int month, int year);
  void destroy();
  bool equal(Day *day2);
  bool lessThan(Day *day2);
  void print();
  void read();
  void subjectSearch(char *subject);
}; // class Day

#endif	// DAY_H 

