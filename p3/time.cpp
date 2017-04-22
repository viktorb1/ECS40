// Author: Sean Davis

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"

bool Time::lessThan(const Time *time2) const
{
  return hour < time2->hour 
    || (hour == time2->hour && minute < time2->minute);
} // lessThan()


void Time::print() const
{
  printf("%02d:%02d ", hour, minute);
} // print()


void Time::read()
{
  char *ptr;
  
  hour = atoi(strtok(NULL, ":"));
  minute = atoi(strtok(NULL, ":"));
  ptr = strtok(NULL, ",");
  
  if(strchr(ptr, 'A'))
  {
    if (hour == 12)
      hour -= 12;
  }
  else
    hour+= 12;
  
} // read()
