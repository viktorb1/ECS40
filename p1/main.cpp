#include <stdio.h>
#include "calendar.h"

int getChoice();

int main()
{
  Calendar calendar;

  create(&calendar);
  readFile(&calendar);
  
  int x = getChoice();

  while(1)
  {
    if (x == 0) //0: done
    {
      destroy(&calendar);
      break;
    } // if user selects option 0 "done"
    else //runs choices 1 or 2
    {
      if (x == 1) //1: search for date
          dateSearch(&calendar);

      if (x == 2) //2: search for subject
        subjectSearch(&calendar);
    } //else if user selects option 2 "search for subject"
    
    x = getChoice();
  } // while 1, loop forever until user selects option '0'

  return 0;
} //main()

int getChoice()
{
  int selection;

  printf("Calendar Menu\n0. Done\n1. Search for date.\n");
  printf("2. Search for subject.\n\nYour choice >> ");
  scanf("%d", &selection);

  char trash = '\0';

  while (trash != '\n')
    scanf("%c", &trash);

  while (selection < 0 || selection > 2)
  {
    printf("Choice must be between 0 and 2.  Please try again.\n\n");
    printf("Calendar Menu\n0. Done\n1. Search for date.\n");
    printf("2. Search for subject.\n\nYour choice >> ");
    scanf("%d", &selection);

    trash = '\0';
    
    while (trash != '\n')
      scanf("%c", &trash);
  } // while selection is not 0, 1 or 2

  return selection;
} //getChoice()