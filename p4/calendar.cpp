// Author: Sean Davis
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "calendar.h"
#include "day.h"
#include "time.h"

using namespace std;

Calendar::Calendar() : size(30), count(0)
{
  days = new Day[30];
} // Calendar()


Calendar::~Calendar()
{  
  delete [] days;
}  // destroy()


void Calendar::addAppointment()
{
  int day = -1, month = -1, year = -1;
  getDate(&day, &month, &year);
  Day dayTemp(day, month, year);
  int hour, minute;
  char subject[80], location[80], temp[7];

  cout << "Subject >> ";
  fgets(subject, 80, stdin);
  subject[strlen(subject) - 1] = '\0';
  cout << "Location >> ";
  fgets(location, 80, stdin);
  location[strlen(location) - 1] = '\0';
  cout << "Start time (hh:mm) >> ";
  fgets(temp, 7, stdin);
  hour = atoi(strtok(temp, ":"));
  minute = atoi(strtok(NULL, ":"));
  Time startTime(hour, minute);
  cout << "End time (hh:mm) >> ";
  fgets(temp, 7, stdin);
  hour = atoi(strtok(temp, ":"));
  minute = atoi(strtok(NULL, ":"));
  Time endTime(hour, minute);


  for(int i = 0; i < count; i++)
    if(days[i].equal(&dayTemp))
    {
      days[i].addAppointment(subject, location, startTime, endTime);
      return;
    } // if the day with the corresponding date already exists
  
  dayTemp.addAppointment(subject, location, startTime, endTime);
  addNewDay(dayTemp);
} // addAppointment()


void Calendar::dateSearch() const 
{
  int day = -1, month = -1, year = -1;
  getDate(&day, &month, &year);
  Day dayTemp(day, month, year);
  
  for(int i = 0; i < count; i++)
    if(days[i].equal(&dayTemp))
    {
      days[i].print();
      return;
    } // if found matching date
  
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

void Calendar::readFile()
{
  ifstream inf("appts.csv");
  char line[80];
  int day, month, year, pos;
  inf.getline(line, 80);  // get rid of label line;
  
  while(inf.getline(line, 80))
  {
    month = atoi(strtok(line, "/"));
    day = atoi(strtok(NULL, "/"));
    year = atoi(strtok(NULL, ","));
    Day dayTemp(day, month, year);
    
    for(pos = 0; 
      pos < count && !dayTemp.equal(&days[pos]); pos++); 
    
    if(pos == count) // not found
    {
      if(count == size)
        resize();
      
      for(pos = count - 1; 
        pos >= 0 && dayTemp.lessThan(&days[pos]); pos--)
          days[pos + 1] = days[pos];
      
      days[++pos] = dayTemp;  // copy the new day into pos + 1
      count++;
    } // if not found
    
    days[pos].read();
  } // while more lines in the file
  
  inf.close();
}  // readFile()

void Calendar::resize()
{
  Day *temp = new Day[size * 2];
  
  for(int i = 0; i < count; i++)
    temp[i] = days[i];
  
  delete [] days;
  days = temp;
  size *= 2;
}  // resize()


void Calendar::subjectSearch() const
{
  char subject[80];
  cout << "Please enter the subject >> ";
  fgets(subject, 80, stdin);
  
  if(strlen(subject) > 0)
    subject[strlen(subject) - 1] = '\0';  // eliminate the '\n'
  
  cout << "Date                          Start End   Subject      Location\n";
  
  for(int i = 0; i < count; i++)
    days[i].subjectSearch(subject);
  
  cout << "\n";
}  // subjectSearch()

void Calendar::addNewDay(const Day& dayTemp)
{
  int pos;

    for(pos = 0; 
  pos < count && !dayTemp.equal(&days[pos]); pos++); 
    
  if(pos == count) // not found
  {
    if(count == size)
      resize();
    
    for(pos = count - 1; 
      pos >= 0 && dayTemp.lessThan(&days[pos]); pos--)
        days[pos + 1] = days[pos];
    
    
    days[++pos] = dayTemp;  // copy the new day into pos + 1
    count++;
  } // if not found
} // addNewDay()
