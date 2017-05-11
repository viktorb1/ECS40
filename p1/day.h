#ifndef _DAY_H_
#define _DAY_H_

#include "appt.h"

typedef struct
{
  short day;
  short month; 
  short year;
  Appointment* appts[8];
  short apptCount;
} Day;

void create(Day *dayTemp, short day, short month, short year);
int equal(Day *dayTemp, Day *day);
int lessThan(Day *dayTemp, Day *day);
void read(Day *day);
void print(Day *day);
void subjectSearch(Day *day, char *userInput);
void destroy(Day *day);

#endif