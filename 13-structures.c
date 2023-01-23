/**************************************
Notes
  tool for grouping elements together - like OOP without methods
  Structure Declaration Syntax
    struct date {
      int month;
      int day;
      int year:
    }
  
  The variable names within the structure are called members or fields
  The declaration statement defines what the structure looks like to the C Compiler but there is no memory alloction for just the declaration
  A structure defines a new type in the language, variables can be declared to be of type struct 
  i.e.
  struct date today;

  Accessing members of a struct
   i.e.
    today.day = 25;

***************************************/

#include <stdio.h>

int main() {
  struct date {
   int month;
   int day;
   int year;
  };
  
  struct date today;
  
  today.month = 9;
  today.day = 25;
  today.year = 2015;
  
  printf("Todays date is %d/%d/%d\n", today.month, today.day, today.year);
  return 0;
}
