#ifndef _APPT_H_
#define _APPT_H_

#include "time.h"

typedef struct
{
  Time startTime;
  Time endTime;
  char *subject;
  char *location;
} Appointment;

void print(Appointment *appt);
int lessThan(Appointment *apptTemp, Appointment *appt);
void read(Appointment *apptTemp);
int equal(Appointment* appt, char* userInput);
void destroy(Appointment *appt);

#endif