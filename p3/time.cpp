// Author: Sean Davis

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"

bool Time::lessThan(Time *time2)
{
  return hour < time2->hour 
    || (hour == time2->hour && minute < time2->minute);
} // lessThan()


void Time::print()
{
  printf("%02d:%02d ", hour, minute);
} // print()


void Time::read()
{
  char *ptr;
  
  hour = atoi(strtok(NULL, ":"));
  minute = atoi(strtok(NULL, ":"));
  ptr = strtok(NULL, ",");
  
  if(strchr(ptr, 'P'))
    hour += 12;
  
} // read()
