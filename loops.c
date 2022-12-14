/**********************************************
For Loop:

  for (starting condition; continuation condition; action per iteration) {
    loop statements;
   }
   
  for(initialize; test; update)
    body;
   
  Variables will be local to the loop and will not exist once the loop ends
  Continuation condition is tested at the beginning of the loop (pre-test loop) i.e loop statment
   will not be executed at all if the continuation condition starts out false
  Action per iteration is exectuted at the end of each loop iteration
  Depending on version of C compiler may have to declare the control variables outside the loop
  C99 has declaration and initialization inside for loop
  
  Infinite For Loop - maybe used for monitoring data or listening for connections
  for(;;) {
    statements;
  }
  
While Loop:

  while(expression) {
    statements;
  }
  
  Condition for continuation of the while loop is tested at the start (pre-test loop)
    i.e. will not be executed at all if the condition starts out false
  
Do While Loop:
  Post-test - first iteration is executed for the first time unconditionally
  Exit control loop
  
  do {
    statements;
  } while(expression);
  
Equivalent - for(;test;) while(test)
**********************************************/

#include <stdio.h>

int main() {
//   for loop - ++count or count++ doesnt matter - modification of counter always happens after execution of loop statements
  for (int i = 1, j = 2; i <= 5; ++i, j = j + 2) {
    printf(" %5d", i * j);  
  }
  
  unsigned long long sum = 0LL; //sum of integers
  unsigned int count = 0; //number of ints to be summed
  
//   user input
  printf("\nEnter the number of integers you want to sum: ");
  scanf(" %u", &count);
  
//   sum ints from 1 to count
  for(unsigned int i = 1; i <= count; ++i) {
    sum += i;
  }
  
//   alternatively - single line
//   for (unsigned int i = 1; i <= count; sum += i++);
  
//   output
  printf("\nTotal of the first %u numbers is %llu\n", count, sum);
  
//   While loop
  int wCount = 1;
  
  while(wCount<=5){
    printf("%i\n", wCount);
    ++wCount;
  }
  
  int num = 0;
  scanf("%d", &num);
  
  while(num != -1) {
    scanf("%d", &num);
  }
  
//   do while
  int dCounter = 0;
  do {
    printf("\nNumber = %d", dCounter);
    dCounter++;
  } while(dCounter < 10);
   
  return 0;
}
