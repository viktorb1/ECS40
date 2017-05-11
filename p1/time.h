#ifndef _TIME_H_
#define _TIME_H_

typedef struct
{
  short hour;
  short minute;
} Time;

void read(Time *time);
void print(Time *time);
int lessThan(Time *time1, Time *time2);

#endif