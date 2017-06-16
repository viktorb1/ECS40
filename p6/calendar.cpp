#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "calendar.h"
#include "day.h"
#include "DayOfWeek.h"

using namespace std;

Calendar::Calendar() : days(30)
{} // Calendar()


void Calendar::addAppointment()
{
  int pos, day, month, year;
  getDate(&day, &month, &year);
  Day dayTemp(day, month, year);
  pos = (days += dayTemp);
  days[pos].addAppointment();
}  // addAppointment()


void Calendar::dateSearch() const
{
  int day = -1, month = -1, year = -1;
  getDate(&day, &month, &year);
  Day dayTemp(day, month, year);
  
  for(int i = 0; i < days.getCount(); i++)
  {
    if(days[i] ==  dayTemp)
    {
      cout << days[i];
      return;
    } // if found matching date
  } // loop through days and check if they are equal
  
  cout << "That date was not found.\n";
}  // dateSearch()


void Calendar::getDate(int *day, int *month, int *year) const
{
  while(true)
  {
    char line[80], line2[80], *ptr;
    cout << "\nPlease enter the month, day, and year (mm/dd/yyyy) >> ";
    
    if (! fgets(line, 80, stdin))
      cout << " is not a valid date.\nPlease try again.\n";
    else // User entered something
    {
      strtok(line, "\n");
      strcpy(line2, line);
      ptr = strtok(line, "/");
      
      if(ptr)
      {
        *month = atoi(ptr);
        ptr = strtok(NULL, "/");
        
        if(ptr)
        {
          *day = atoi(ptr);
          ptr = strtok(NULL, "\n");
          
          if(ptr)
            *year = atoi(ptr);
        } // if something before a second /
      } // if something before the first /
      
      if(*day >= 1 && *day <= 31 && *month >= 1 && *month <= 12 
         && *year >= 1000 && *year <= 2017)
         break;
      
      cout << line2 << " is not a valid date.\nPlease try again.\n";
    } // else use entered something
  } // while invalid date
}  // getDate()

istream& operator>> (istream &is, Calendar &calendar)
{
  char line[80];
  int day, month, year, pos;
  is.getline(line, 80);  // get rid of label line;
  const WeeklyAppointment *appt;
  
  while(is.getline(line, 80, '/'))
  {
    month = atoi(line);
    is.getline(line, 80, '/');
    day = atoi(line);
    is.getline(line, 80, ',');
    year = atoi(line);
    Day dayTemp(day, month, year);
    pos = (calendar.days += dayTemp);
    appt = dynamic_cast<const WeeklyAppointment*>(is >> calendar.days[pos]);

    if(appt)
      calendar.createSeries(*appt, month, day, year);


  } // while more lines in the file
  
  return is;
}  // operator>> ()


void Calendar::createSeries(WeeklyAppointment wa, int month, int day, int year)
{
  int pos, i = 1, j = 0;
  const char *copy = wa.getSeries();
  ifstream inf("DOW.dat", ios::binary);

  while (i < wa.getSeriesCount())
  {
    if (day >= 31 && month < 12)
      day = 1, month++;
    else // if not new month
    {
      if (day >= 31 && month >= 12)
        day = 1, month = 1, year++;
      else // if not new month or not new year
        day++;
    } // increment the day 
    
    DayOfWeek dayOfWeek(month, day, year);
    inf >> dayOfWeek;

    for (j = 0; j < (int)strlen(copy); j++)
    {
      if (dayOfWeek == copy[j])
      {
        Day dayTemp(day, month, year);
        pos = (days += dayTemp); // gets position of new day
        days[pos] += wa; // adds it to appts linkedlist
        i++;
      } // check if character in series array matches
    } // loop through series array
  } // repeat until getSeries() appointments were added
} // createSeries()


void Calendar::subjectSearch() const
{
  char subject[80];
  cout << "Please enter the subject >> ";
  fgets(subject, 80, stdin);
  
  if(strlen(subject) > 0)
    subject[strlen(subject) - 1] = '\0';  // eliminate the '\n'
  
  cout << "Date                          Start End   Subject      Location\n";
  
  for(int i = 0; i < days.getCount(); i++)
    days[i].subjectSearch(subject);
  
  cout << "\n";
}  // subjectSearch()


