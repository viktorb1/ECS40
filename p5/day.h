#ifndef DAY_H
#define	DAY_H
// Author: Sean Davis
#include "appt.h"
#include "linkedlist.h"

class Day
{
  short day;
  short month;
  short year;
  LinkedList appts;
  short apptCount;
public:
  Day();
  Day(int day1, int month, int year);
  void addAppointment();
  bool operator==(const Day &day2) const;
  bool operator<(const Day &day2) const;
  Day& operator=(const Day &day);
  friend ostream & operator<<(ostream & os, const Day & day);
  friend istream & operator>>(istream & in, Day & day);
  void subjectSearch(const char *subject) const;
}; // class Day




#endif	// DAY_H 

