// Author: Sean Davis

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "appt.h"
#include "time.h"


void Appointment::destroy()
{
  free(subject);
  free(location);
}  // destroy()


bool Appointment::equal(char *subjectkeyword)
{
  return strstr(subject, subjectkeyword) != NULL;
}  // equal()


bool Appointment::lessThan(Appointment *appointment2)
{
  return startTime.lessThan(&appointment2->startTime); 
}  // lessThan()


void Appointment::print()
{
  startTime.print();
  endTime.print();
  printf("%-13s%s\n", subject, location);
} // print()


void Appointment::read()
{
  char *ptr;
  ptr = strtok(NULL, ",");
  subject = (char*) malloc(strlen(ptr) + 1);
  strcpy(subject, ptr);
  startTime.read();
  endTime.read();
  ptr = strtok(NULL, "\n");
  location = (char*) malloc(strlen(ptr) + 1);
  strcpy(location, ptr);
} // read()

