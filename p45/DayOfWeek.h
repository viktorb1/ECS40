#ifndef DAY_OF_WEEK_H
#define DAY_OF_WEEK_H

class DayOfWeek
{
  char monthName[10];
  int month;
  int day;
  int year;
  char dayName[10];

public:
  void read(int month, int day, int year);
  void print();
}; // class DayOfWeek

#endif