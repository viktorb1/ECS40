// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "time.h"

using namespace std;

bool Time::lessThan(const Time *time2) const
{
  return hour < time2->hour 
    || (hour == time2->hour && minute < time2->minute);
} // lessThan()


void Time::print() const
{
  cout << setw(2) << setfill('0') <<  hour << ":" << setw(2) << minute 
    << ' ' << setfill(' ');
} // print()


void Time::read()
{
  char *ptr;
  
  hour = atoi(strtok(NULL, ":"));
  minute = atoi(strtok(NULL, ":"));
  ptr = strtok(NULL, ",");

  if(hour == 12 && strchr(ptr, 'A'))
    hour = 0;
  
  if(strchr(ptr, 'P') && hour < 12)
    hour += 12;
  
} // read()

Time::Time()
{}

Time::Time(short hour1, short min1) : hour(hour1), minute(min1)
{}
