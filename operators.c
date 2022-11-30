/**********************************************************
Notes:
Operators in C
  infix stype - inbetween the data
  Logical Operator/Boolean Operator - Returns boolean based on 2 expressions
  Arithmetic (+, -, *, /)
  assignment (=)
  relational (<, >, !=)
  bitwise (<<, >>, ~)
Expressions and Statements in C
  Statements are the basic program steps of C, most statements are constructed from expressions
    building blocks of a program
    a complete instruction to the computer
    C considers any expression to be a statement if you append a semicolon
  Expression - consists of a combination of operators and operands
    operands are what the operator operates on
    operands can be constant, variables, or combination of two
    every expression has a value
  Compound Statement
    
**********************************************************/

#include <stdio.h>

int main() {
  //declaration statement
  int myAge;
  //assignment statement
  myAge = 36;
  //function call statement
  printf("I am learning C");
  //structure statement:
  while (myAge < 40 ) myAge = myAge + 1;
  // Return statement;
  return 0;
}
