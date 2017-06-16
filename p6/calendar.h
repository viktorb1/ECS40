#ifndef CALENDAR_H
#define	CALENDAR_H
// Author: Sean Davis

#include "day.h"
#include "vector.h"

class Calendar
{
  Vector<Day> days;
public:
  Calendar();
  void addAppointment();
  void dateSearch() const;
  int findDate(int day, int month, int year);
  void getDate(int *day, int *month, int *year) const;
  friend istream& operator>> (istream &is, Calendar &calendar); 
  void resize();
  void subjectSearch() const;
  void createSeries(WeeklyAppointment wa, int month, int day, int year);
};  // class Calendar
#endif	// CALENDAR_H 

