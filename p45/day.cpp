// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include "day.h"
#include "appt.h"
#include "DayOfWeek.h"

using namespace std;

Day::Day(int day1, int month1, int year1) :
  day(day1),
  month(month1),
  year(year1),
  apptCount(0)
{}  // Day()


Day::Day() : apptCount(0)
{}


Day& Day::operator=(const Day& rhs)
{
  if (this == &rhs)
    return *this;

  for (int i = 0; i < apptCount; i++)
    delete appts[i];

  for (int i = 0; i < rhs.apptCount; i++)
    if (rhs.appts[i])
      appts[i] = new Appointment(*rhs.appts[i]);
    else // the appointment does not exist in rhs
      appts[i] = NULL;

  day = rhs.day;
  month = rhs.month;
  year = rhs.year;
  apptCount = rhs.apptCount;

  return *this;
} // Operator()


Day::~Day()
{
  for(int i = 0; i < apptCount; i++)
    delete appts[i];
}  // destroy()


void Day::addAppointment(char* subject, char* location, Time start, Time end)
{
  int pos;
  Appointment *appointment = new Appointment(start, end, subject, location);
  
  for(pos = apptCount - 1; 
    pos >= 0 && appointment->lessThan(appts[pos]); pos--)
      appts[pos + 1] = appts[pos];
  
  appts[pos + 1] = appointment;
  apptCount++;
} // addAppointment()


bool Day::equal(const Day *day2) const
{
  return day == day2->day && month == day2->month 
    && year == day2->year;
} // equal()


bool Day::lessThan(const Day *day2) const
{
  return (year < day2->year)
    || (year == day2->year && month < day2->month)
    || (year == day2->year && month == day2->month 
      && day < day2->day); 
} // lessThan()


void Day::print() const
{
  cout << "Start End   Subject      Location\n";
  
  for(int i = 0; i < apptCount; i++)
    appts[i]->print();
  
  cout << "\n";
} // print()


void Day::read()
{
  int pos;
  Appointment *appointment = new Appointment;
  appointment->read();
  
  for(pos = apptCount - 1; 
    pos >= 0 && appointment->lessThan(appts[pos]); pos--)
      appts[pos + 1] = appts[pos];
  
  appts[pos + 1] = appointment;
  apptCount++;
} // read()


void Day::subjectSearch(const char *subject) const
{
  DayOfWeek dayofweek;
  
  for(int i = 0; i < apptCount; i++)
    if(appts[i]->equal(subject))
    {
      dayofweek.read(month, day, year);
      dayofweek.print();
      appts[i]->print();
    } // if appointment has the subject
      
} // subjectSearch()
