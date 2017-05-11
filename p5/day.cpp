// Author: Sean Davis
#include <fstream>
#include <iostream>
#include <iomanip>
#include "day.h"
#include "linkedlist.h"
#include "appt.h"
#include "DayOfWeek.h"


using namespace std;

Day::Day() : apptCount(0)
{
}  // Day()


Day::Day(int day1, int month1, int year1) : day(day1), month(month1), 
  year(year1), apptCount(0)
{
}  // Day(int, int, int)


void Day::addAppointment()
{  
  Appointment *appointment = new Appointment();
  appointment->addAppointment();
  appts += appointment;
  apptCount++;
}  // addAppointment()


bool Day::operator==(const Day &day2) const
{
  return day == day2.day && month == day2.month 
    && year == day2.year;
} // operator==


bool Day::operator<(const Day &day2) const
{
  return (year < day2.year)
    || (year == day2.year && month < day2.month)
    || (year == day2.year && month == day2.month 
      && day < day2.day); 
} // operator<



Day& Day::operator=(const Day &rhs) 
{
  if(this == &rhs)
    return *this;

  day = rhs.day;
  month = rhs.month;
  year = rhs.year;

  apptCount = rhs.apptCount;  
  
  appts = rhs.appts;
  
  return *this;
}  // operator=


ostream & operator<<(ostream & os, const Day & day)
{
  os << "Start End   Subject      Location\n";
  
  os << day.appts;
  
  os << "\n";
  
  return os;
} // operator<<


istream & operator>>(istream & in, Day & day)
{
  Appointment *appointment = new Appointment;
  in >> *appointment;
  day.appts += appointment;
  day.apptCount++;
  return in;
} // operator>>


void Day::subjectSearch(const char *subject) const
{
  ifstream inf("DOW.dat", ios::binary);
  Appointment *location = appts.find(subject);
   
  while(location != NULL)
  {
    DayOfWeek userDay(month, day, year);
    inf >> userDay;
    cout << userDay;
    cout << *location; 
    location = appts.find(subject);
  } // while subject exists in appts

  inf.close();
} // subjectSearch()