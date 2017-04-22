// Author: Sean Davis

#ifndef TIME_H
#define	TIME_H

class Time
{
  short hour;
  short minute;

public:
  bool lessThan(Time *time2);
  void print();
  void read();
}; // Time


#endif	// TIME_H 

