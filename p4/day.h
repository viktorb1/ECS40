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
  Day();
  ~Day();
  Day(int day1, int month1, int year1);
  Day& operator=(const Day& rhs);
  bool equal(const Day *day2) const;
  bool lessThan(const Day *day2) const;
  void print() const;
  void read();
  void subjectSearch(const char *subject) const;
  void addAppointment(char* subject, char* location, Time start, Time end);
}; // class Day




#endif	// DAY_H 

