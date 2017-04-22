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
  cout << setfill('0') << setw(2) << hour << setfill('0') << ":"
  << setw(2) << minute << " " << setfill(' ');
} // print()


void Time::read()
{
  char *ptr;
  
  hour = atoi(strtok(NULL, ":"));
  minute = atoi(strtok(NULL, ":"));
  ptr = strtok(NULL, ",");
  
  if(strchr(ptr, 'P'))
    if (hour < 12)
      hour += 12;

  if(strchr(ptr, 'A'))
    if (hour == 12)
      hour -= 12;
  
} // read()
