/*************************************
Notes - Control Flow
Types of Control Flow in C
  Decision Making
    if-then
      if (expression) { 
        statements; 
      } // curly braces not required if not multiple statments
    if-then-else
      if (expression) { 
        statements; 
      }
      else {
        statements;
      }
    if-then-else if-else
      if (expression) {
        statements;
      }
      else if (expression) {
        statements;
      }
      else {
        statements;
      }
    Ternary operator - takes three operands
      conditional operator - can only have single statements
        condition ? if condition true then expression 1 : if condition false then expression 2
    switch - use when the value of a variable is successively compared against different
      switch (expression) {
        case value 1:
          statements;
          break;
        case value n:
          statements;
          break;
        default:
          statements;
          break;
      }
    goto
  Looping/Repeating - variables created inside a loop have scope only inside the loop
    for - repeat statements multiple times
    while - repeat while a given condition is true, tests the condition before executing loop body
    do-while - same as while except tests the condition after executing loop body
  Branching
    break
    continue
    return
**************************************/

#include <stdio.h>

int main()
{
  int test_num, remainder;

  printf("Enter your number to be tested: ");
  scanf("%i", &test_num);

  remainder = test_num % 2;

  if (remainder == 0)
  {
    printf("The number is even\n");
  }
  else
  {
    printf("The number is odd\n");
  }

  int number, sign;

  printf("Enter a number: ");
  scanf("%i", &number);

  if (number < 0) {
    sign = -1;
  } else if (number == 0) {
    sign = 0;
  } else {
    sign = 1;
  }

  printf("Sign = %i\n", sign);
  
  int x, y;
  
  printf("Enter a value for y: ");
  scanf("%i", &y);

  x = y > 7 ? 25 : 50; // results in x being set to 25 if y is greater than 7, or to 50 otherwise

  printf("X = %i\n", x);

  return 0;
}