#ifndef _CALENDAR_H_
#define _CALENDAR_H_

#include "day.h"

typedef struct 
{
  Day *days;
  int size;
  int count;
} Calendar;

void create(Calendar *calendar);
void readFile(Calendar *calendar);
void resize(Calendar *calendar);
void dateSearch(Calendar *calendar);
void getDate(short* month, short* day, short* year);
void subjectSearch(Calendar *calendar);
void destroy(Calendar *calendar);
int equal(Day *dayTemp, Calendar *calendar);
void addDay(Day* dayTemp, Calendar* calendar, int i);

#endif