#include <stdio.h>
#include "time.h"
#include <stdlib.h>
#include <string.h>

void read(Time *time)
{
  time->hour = atoi(strtok(NULL, ":"));
  time->minute = atoi(strtok(NULL, " "));

  char* timePeriod = strtok(NULL, ",");
  
  if (strcmp(timePeriod, "PM") == 0)
    time->hour += 12;
} // read()

void print(Time *time)
{
  printf("%02d:%02d ", time->hour, time->minute);
} // print()

int lessThan(Time *time1, Time *time2)
{
  if (time1->hour < time2->hour)
    return 1;

  if (time1->hour == time2->hour)
    if (time1->minute < time2->minute)
      return 1;

  return 0;
} //lessThan()