#include "calendar.h"
#include "day.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create(Calendar *calendar) 
{
  calendar->size = 30;
  calendar->count = 0;
  calendar->days = (Day*)calloc(calendar->size, sizeof(Day));
} // create()

void readFile(Calendar *calendar) 
{
  FILE *fp = fopen("appts.csv", "r");
  char str[80];
  int day, month, year, i = 0, j = 0;
  Day dayTemp;
  fgets(str, 80, fp);

  while(fgets(str, 80, fp) != NULL) 
  {
    month = atoi(strtok(str, "/"));
    day = atoi(strtok(NULL, "/"));
    year = atoi(strtok(NULL, ","));
    create(&dayTemp, day, month, year);

    for (i = 0; i < calendar->count; i++)
    {
      if (equal(&dayTemp, &calendar->days[i]))
        break;

      if (calendar->count == calendar->size)
        resize(calendar);

      if (lessThan(&dayTemp, &calendar->days[i]))
        {
          for (j = calendar->count - 1; j >= i; j--)
            calendar->days[j + 1] = calendar->days[j];
          break;          
        } // if the new date is older
    } // for each date in the calendar->days array

    addDay(&dayTemp, calendar, i);
    read(&calendar->days[i]);
  } // while each line is read

  fclose(fp);
} // readFile()

void resize(Calendar *calendar) 
{
  calendar->size = calendar->size*2;
  Day *resizedDay = (Day*)malloc(sizeof(Day)*calendar->size);

  for(int i = 0; i < calendar->count; i++)
    resizedDay[i] = calendar->days[i];

  free(calendar->days);
  calendar->days = resizedDay;
} // resize()

void dateSearch(Calendar *calendar) 
{
  short month, day, year;
  int i = 0, missing = 0;
  Day date;
  
  getDate(&month, &day, &year);
  create(&date, day, month, year);

  for(i = 0; i < calendar->count; i++)
  {
    if (equal(&date, &calendar->days[i]))
    {
      missing = 0;
      break;
    } // if the two dates are equal
    else // couldn't find date in caledar->days array
      missing = 1;
  } // for each date in the calendar->days array
      
  if (missing == 1)
    printf("That date was not found.\n");
  else // date found (so print subjects\locations etc)
    print(&calendar->days[i]);
} // dateSearch()

void getDate(short* month, short* day, short* year)
{
  char str[80], copy[80];
  char* temp;

  while(1)
  {
    printf("\nPlease enter the month, day, and year (mm/dd/yyyy) >> ");
    fgets(str, 80, stdin);
    str[strlen(str)-1] = '\0';
    strcpy(copy, str);

    if ((temp = strtok(copy, "/")) != NULL)
      *month = atoi(temp);

    if ((temp = strtok(NULL, "/")) != NULL)
      *day = atoi(temp);
    
    if ((temp = strtok(NULL, "\n")) != NULL)
      *year = atoi(temp);

    if (*month <= 12 && *month >= 1) 
      if(*day <= 31  && *day >= 1)
        if(*year <= 2017 && *year >= 1000)
          return;
    
    printf("%s is not a valid date.\nPlease try again.\n", str);  
  } // while()
} // getDate()

void subjectSearch(Calendar *calendar)
{
  printf("Please enter the subject >> ");
  char userInput[80];
  fgets(userInput, 80, stdin);
  userInput[strlen(userInput) - 1] = '\0';

  printf("Date       Start End   Subject      Location\n");

  for (int i = 0; i < calendar->count; i++)
    subjectSearch(&calendar->days[i], userInput);

  printf("\n");
} // subjectSearch()

void destroy(Calendar *calendar)
{
  for (int i = 0; i < calendar->count; i++)
    destroy(&calendar->days[i]);

  free(calendar->days);
} // destroy()


void addDay(Day* dayTemp, Calendar* calendar, int i)
{
  if(!equal(dayTemp, &calendar->days[i]))
    {
      calendar->days[i] = *dayTemp;
      calendar->count++;
    } // if the dates are not equal
} // addDay()