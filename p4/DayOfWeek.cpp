#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "DayOfWeek.h"

using namespace std;

void DayOfWeek::read(int month1, int day1, int year1)
{
  ifstream inf("DOW.dat");

  int daysSince111990 = (month1 - 1) * 31 + (day1 - 1) + (year1 - 1990) * 372;
  int location = 36 * daysSince111990;

  inf.seekg(location, inf.beg);
  inf.read(monthName, 10);
  inf.seekg(location + 24);
  inf.read(dayName, 10);

  month = month1;
  day = day1;
  year = year1;

  inf.close();
} // read()

void DayOfWeek::print() const
{
  char temp[31];
  char dayStr[3];
  int dayTemp;

  strcpy(temp, dayName);
  strcat(temp, ", ");
  strcat(temp, monthName);
  strcat(temp, " ");

  int i = 0;

  if (day >= 10)
  {
    dayTemp = day / 10;
    dayStr[i] = dayTemp + '0';
    i++;
  } // if day has two digits

  dayTemp = day % 10;
  dayStr[i] = dayTemp + '0';
  dayStr[++i] = '\0';

  strcat(temp, dayStr);

  cout << left << setw(30) << temp << right;
} // print()