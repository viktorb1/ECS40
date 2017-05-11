#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "appt.h"
#include "time.h"

void print(Appointment *appt)
{
  print(&appt->startTime);
  print(&appt->endTime);
  printf("%-13s", appt->subject);
  printf("%s\n", appt->location);
} // print()

int lessThan(Appointment *apptTemp, Appointment *appt)
{
  return lessThan(&apptTemp->startTime, &appt->startTime);
} // lessThan()

void read(Appointment *apptTemp)
{
  char* subject = strtok(NULL, ",");
  apptTemp->subject = (char*)malloc(strlen(subject) + 1);
  strcpy(apptTemp->subject, subject);
  
  read(&apptTemp->startTime);
  read(&apptTemp->endTime);

  char* location = strtok(NULL, "\n");
  apptTemp->location = (char*)malloc(strlen(location) + 1);
  strcpy(apptTemp->location, location);
} // read()

int equal(Appointment* appt, char* userInput)
{
  unsigned int size = strlen(appt->subject);

  if(strlen(userInput) < size)
    size = strlen(userInput);

  if (strncmp(userInput, appt->subject, size) == 0)
    return 1;

  return 0;
} // equal()

void destroy(Appointment *appt)
{
  free(appt->subject);
  free(appt->location);
} // destroy()