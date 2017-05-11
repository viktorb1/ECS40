#ifndef CALENDAR_H
#define	CALENDAR_H
// Author: Sean Davis

#include "day.h"

class Calendar
{
  Day *days;
  int size;
  int count;
public:
  Calendar();
  ~Calendar();
  void dateSearch() const;
  void getDate(int *day, int *month, int *year) const;
  void readFile();
  void resize();
  void subjectSearch() const;
  void addAppointment();
  void addNewDay(const Day& dayTemp);
};  // class Calendar
#endif	// CALENDAR_H 

