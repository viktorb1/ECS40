#include "day.h"
#include "appt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create(Day *dayTemp, short day, short month, short year)
{
  dayTemp->day = day;
  dayTemp->month = month;
  dayTemp->year = year;
  dayTemp->apptCount = 0;
} // create()

int equal(Day *dayTemp, Day *day)
{
  if (dayTemp->day == day->day)
    if (dayTemp->month == day->month)
      if (dayTemp->year == day->year)
        return 1;
  
  return 0;
} // equal()

int lessThan(Day *dayTemp, Day *day)
{
  if (dayTemp->year < day->year)
    return 1;

  if (dayTemp->year == day->year)
    if (dayTemp->month < day->month)
      return 1;

  if (dayTemp->year == day->year)
    if (dayTemp->month == day->month)
      if (dayTemp->day < day->day)
        return 1;

  return 0;
} //lessThan()

void read(Day *day)
{
  int i = 0;

  Appointment* apptTemp = (Appointment*)malloc(sizeof(Appointment));
  read(apptTemp);

  for (i = day->apptCount; i >= 0; i--)
  {
    if(i != 0 && lessThan(apptTemp, day->appts[i-1]))
    {
      day->appts[i] = day->appts[i-1];
    } // if the appointment's time is less than the new appointment's time
    else // apptTemp startTime was greater than the ith appt's in day
    {
      day->appts[i] = apptTemp;
      day->apptCount++;
      break;
    } // else
  } // for each appointment in the day
} //read()

void print(Day *day)
{
  int i = 0;
  printf("Start End   Subject      Location\n");
  
  for (i = 0; i < day->apptCount; i++)
    print(day->appts[i]);

  printf("\n");
} //print()

void subjectSearch(Day *day, char *userInput) 
{
  for(int i = 0; i < day->apptCount; i++)
  {
    if(equal(day->appts[i], userInput))
    {
      printf("%2d/%2d/%2d ", day->month, day->day, day->year);
      print(day->appts[i]);
    } // if the user input matches an appointment for the day
  } // for each appointment in the day
} //subjectSearch()

void destroy(Day *day)
{
  for (int i = 0; i < day->apptCount; i++)
    destroy(day->appts[i]);
  
  for (int i = 0; i < day->apptCount; i++)
    free(day->appts[i]);
} // destroy()