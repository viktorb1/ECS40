// Author: Sean Davis
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calendar.h"
#include "day.h"

void Calendar::create()
{
  count = 0;
  size = 30;
  days = (Day*) malloc(30 * sizeof(Day));
} // create()


void Calendar::dateSearch()
{
  int day = -1, month = -1, year = -1;
  Day dayTemp;
  getDate(&day, &month, &year);
  dayTemp.create(day, month, year);
  
  for(int i = 0; i < count; i++)
    if(days[i].equal(&dayTemp))
    {
      days[i].print();
      return;
    } // if found matching date
  
  printf("That date was not found.\n");
}  // dateSearch()


void Calendar::destroy()
{
  for(int i = 0; i < count; i++)
    days[i].destroy();
   
  free(calendar->days);
}  // destroy()


void getDate(int *day, int *month, int *year)
{
  while(true)
  {
    char line[80], line2[80], *ptr;
    printf("\nPlease enter the month, day, and year (mm/dd/yyyy) >> ");
    
    if (! fgets(line, 80, stdin))
      printf(" is not a valid date.\nPlease try again.\n");
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
      
      printf("%s is not a valid date.\nPlease try again.\n", line2);
    } // else use entered something
  } // while invalid date
}  // getDate()

void Calendar::readFile()
{
  FILE *fp = fopen("appts.csv", "r");
  char line[80];
  int day, month, year, pos;
  Day dayTemp;
  fgets(line, 80, fp);  // get rid of label line
  
  while(fgets(line, 80, fp))
  {
    month = atoi(strtok(line, "/"));
    day = atoi(strtok(NULL, "/"));
    year = atoi(strtok(NULL, ","));
    dayTemp.create(day, month, year);
    
    for(pos = 0; 
      pos < count && !dayTemp.equal(&days[pos]); 
      pos++); 
    
    if(pos == count) // not found
    {
      if(count == size)
        this->resize();
      
      for(pos = count - 1; 
        pos >= 0 && dayTemp.lessThan(&days[pos]); pos--)
          days[pos + 1] = days[pos];
      
      days[++pos] = dayTemp;  // copy the new day into pos + 1
      count++;
    } // if not found
    
    days[pos].read();
  } // while more lines in the file
  
  fclose(fp);
}  // readFile()

void Calendar::resize()
{
  Day *temp = (Day*) malloc(size * 2 * sizeof(Day));
  
  for(int i = 0; i < count; i++)
    temp[i] = days[i];
  
  free(calendar->days);
  days = temp;
  size *= 2;
}  // resize()


void Calendar::subjectSearch() const
{
  char subject[80];
  printf("Please enter the subject >> ");
  fgets(subject, 80, stdin);
  
  if(strlen(subject) > 0)
    subject[strlen(subject) - 1] = '\0';  // eliminate the '\n'
  
  printf("Date       Start End   Subject      Location\n");
  
  for(int i = 0; i < count; i++)
    days[i].subjectSearch(subject);
  
  printf("\n");
}  // subjectSearch()


