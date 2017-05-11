// Author: Sean Davis
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "DayOfWeek.h"

using namespace std;

ostream & operator<<(ostream & os, const DayOfWeek & dayOfWeek)
{
  char line[80], dayStr[3];
  strcpy(line, dayOfWeek.dayName);
  strcat(line, ", ");
  strcat(line, dayOfWeek.monthName);
  strcat(line, " ");

  if(dayOfWeek.day > 9)
  {
    dayStr[0] = dayOfWeek.day / 10 + '0';
    dayStr[1] = dayOfWeek.day % 10 + '0';
    dayStr[2] = '\0';
  } // if day > 9
  else // day < 10
  {
    dayStr[0] = dayOfWeek.day + '0';
    dayStr[1] = '\0';
  } // else day < 10

  strcat(line, dayStr);
  os << left << setw(30) << line << right;
  return os;
}  // operator<<


DayOfWeek::DayOfWeek(int month1, int day2, int year3) :
month(month1), day(day2), year(year3)
{  
} // DayOfWeek constructor


istream & operator>>(istream & inf, DayOfWeek & userDay)
{
  int currentDay = userDay.year - 1990;
  int currentMonth = userDay.month - 1;
  int dateNumber = (currentMonth) * 31 + userDay.day - 1 + (currentDay) * 372;
  inf.seekg(dateNumber * sizeof(DayOfWeek));
  inf.read((char*) &userDay, sizeof(DayOfWeek));  // before just used as (this)
  return inf;
}  // operator>>

