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
    
  Can define a struct and declare a variable all together and assign inital values
  
    struct date {
     int month;
     int day;
     int year;
    } today;
  
  Can have unamed struct - must declare the variable with the definition
  
    struct {
     int month;
     int day;
     int year;
    } today;
  
  Initializing structs
  
    struct date today = {7, 2, 2015};
  
    can specify member names
  
    struct date date1 = { .month=12, .day=10} //have to have the dot
  
  Assignment with compound literal (C11)
    
    today = (struct date) {9, 25, 2015};
    
  Structures and Arrays - Array of Structures
    
    struct date myDates[10];
    
    Assigning values
      
      myDates[1].month = 8;
      myDates[1].day = 8;
      myDates[1].year = 1986;
      
    Initializing
    
      struct date myDates[3] = { {12, 10, 1975}, {12,30, 1980}, {11, 15, 2005} };
      
      initialize only a specific element
      
        struct date myDates[3] = { [2] = {12, 10, 1975} }; the 3rd element
      
      initialize only certain members of a specific element
      
        struct date myDates[3] = { [1].month = 12, [1].day = 30 };  
        
    Structures that contain arrays
    
      struct month {
        int numberOfDays;
        char name[3];
      };
      
    Nested Structures
      
      struct time {
        int hours;
        int minutes;
        int seconds;
      };
      
      struct date {
        int month;
        int day;
        int year:
      };
      
      struct dateAndTime {
        struct date sdate;
        struct time stime;
      };
      
      struct dateAndTime event;
      
      event.sdate.month = 10;
      ++event.stime.seconds;
       
      struct dateAndTimeEvent event = {{.month =2, .day = 1, .year = 2015}, {.hour = 3, .minutes = 30, .seconds = 0}}
      
    Array of Nested Structures
    
      struct dateAndTime events[100];
      
      events[0].stime.hour = 12;
      events[0].stime.minutes = 0;
      events[0].stime.seconds = 0;
      
    Declare a structure within a struture
    
      struct Time {
        struct Date {
          int day;
          int month;
          int year;
        } dob;
        
        int hour;
        int minutes;
        int seconds;
      };
      
      in this case the Date struct only has scope within the time struct, cant use the Date struct independently
      use case for this is when you only need the date when associated with a time
      
    Structures and Pointers
      
      pointers to structures are easier to manipulate than structures themselves
      can pass pointer to structure as argument to function
      many data representations use structures contain pointers to other structures
      
      struct date *datePtr = NULL;
      
      datePtr = &todaysDate;
      
      (*datePtr).day = 21;
      
      pointers to structures have a special structure pointer operator ->
        
        if (datePtr->day == 21);

    Can define structures outside of function

    Structures that contain pointers

      struct intPtrs {
        int *p1;
        int *p2;
      };

      struct intPtrs pointers;

    Character arrays and character pointers
      struct names {
        char first[20];
        char last[20];
        }
        
      OR
      
      struct pnames {
        char *first;
        char *last;
      }
        
  struct names veep = {"Talia", "Summers"};
  
  struct pnames treas = {"Brad", "Fallingjaw"};
  
  printf("%s and %s\n", veep.first, treas.first);
  
  struct names variable veep
    strings are stored inside the structure
    structure has allocated a total of 40 bytes to hold the two names
    
  struct pnames variable treas
    strings are stored whever the compiler stores string constants
    structure holds the two addresses, which takes a total of 16 bytes on this system
    struct pnames structure allocates no space to store strings
    it can only be used with strings that have had space allocated for them elsewhere
      such as string constants or strings in arrays
      
    The pointers in a structure should be used only to manage strings that were create and allocated elsewhere in the program
    
    One instance in which it does make sense to use a pointer in a structure to handle a string is if you are dynamically allocating memory
      use a pointer to store the address
      has the adv that you can ask malloc to asllocate just the amount of space that is needed for a string

***************************************/

#include <stdio.h>

void getinfo(struct namect * pst);

void getinfo (struct namect * pst) {
  char temp[SLEN];
  printf("Please enter your name.\n");
  gets_s(temp, SLEN);
  
  //allocate memory to hold name
  pst->fname = (char*)malloc(strlen(temp) + 1);
  
  //copy name to allocated memory
  strcpy(pst->fname, temp);
  printf("Please enter your last name.\n");
  gets_s(temp, SLEN);
  pst->lname = (char*)malloc(strlen(temp) + 1);
  strcpy(pst->lname, temp);
    
  printf("Your name is %s %s", pst->fname, pst->lname);
}

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
  
  struct date myDates[3] = { {12, 10, 1975}, {12,30, 1980}, {11, 15, 2005} };
  
  struct month {
    int numberOfDays;
    char name[3];
  };
  
  struct month monthA = {31, {'J', 'a', 'n'}};
  
  struct month months[12];
  
  //pointers to structs
  
  struct date today2, *datePtr;

  datePtr = &today2;

  datePtr->month = 9;
  datePtr->day = 25;
  datePtr->year = 2015;

  printf("Today's date is %d/%d/%d\n", datePtr->month, datePtr->day, datePtr->year);

  //structs with pointers inside
  
  struct intPtrs {
    int *p1;
    int *p2;
  };

  struct intPtrs pointers;

  int i1 = 100, i2;

  pointers.p1 = &i1;
  pointers.p2 = &i2;
  *points.p2 = -97

  printf("i1 = %i, *points.p1 = %i\n", i1, *pointers.p1);
  printf("i2 = %i, *points.p2 = %i\n", i2, *pointers.p2);
  
  //structs and character pointers
         
  struct namect {
    char *fname;
    char *lname;
    int letters;
  }
  
  struct namect myName; 
  
  getinfo(&myName);

  return 0;
}
