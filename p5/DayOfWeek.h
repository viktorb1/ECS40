#ifndef DAYOFWEEK_H
#define	DAYOFWEEK_H

using namespace std;

class DayOfWeek 
{
  char monthName[10];
  int month;
  int day;
  int year;
  char dayName[10];
public:
  DayOfWeek(int month1, int day2, int year3);
  void read(int month, int day, int year);
  friend ostream & operator<<(ostream & os, const DayOfWeek & dayOfWeek);
  friend istream & operator>>(istream & inf, DayOfWeek & userDay);
}; // class DayOfWeek

#endif	// DAYOFWEEK_H

