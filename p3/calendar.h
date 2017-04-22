#ifndef CALENDAR_H
#define	CALENDAR_H
// Author: Sean Davis

#include "day.h"

class Calendar
{
  Day *days;
  int size;
  int count;

public:
  void create();
  void dateSearch() const;
  void destroy();
  void readFile();
  void resize();
  void subjectSearch() const;
}; // Calendar

void getDate(int *day, int *month, int *year);

#endif	// CALENDAR_H 

