/**********************************************************
Notes:
Operators in C
  infix stype - inbetween the data
  Logical Operator/Boolean Operator - Returns boolean based on 2 expressions - returns a bolean result basd on one or more expressions
  Arithmetic (+, -, *, /) - takes operands and performs a math calc on them
  assignment (=) - asign value of right to left
  relational (<, >, !=) - compare variable against each other
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
    Two or more statements grouped together by enclosing them in braces    
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
  // compound
  int index = 0;
  while (index < 10)
  {
    printf("hello");
    index = index + 1;
  }

  //Arithmetic Operators
  // + add, - subtract, * multiply, / divide, % modulus (remainder after integer division), ++ increment, -- decrement
  int a = 33;
  int b = 15;
  int result = 0;
  
  result = a + b;
  printf("\nadd result is %d\n", result);
  result = a * b;
  printf("\nmultiply result is %d\n", result);
  float div_result = (float)a / b;
  printf("\ndivide result is %f\n", div_result);
  result = a % b;
  printf("\modulus result is %d\n", result);
  printf("\nincrement result is %d\n", ++a); //prefix will increment before statment execution as opposed to putting the ++ after which will increment after statement
  printf("\ndecrement result is %d\n", --a);

  // Logical Operators
  // && AND - If both are non-zero becomes true, || OR - If any of the two operands is zero becomes true, ! NOT - reverse the logical state of its operand
  int c = 5;
  int d;
  _Bool logResult;

  logResult = c && d; // c is not None and d is None, returns false, both need to be not None for true
  printf("\nResult of AND is %i\n", logResult);
  logResult = c || d; // is the value of c or d not None, returns true
  printf("\nResult of OR is %i\n", logResult);
  printf("\nResult of OR is %i\n", !logResult); //reverse above result, returns false

  //Assignment Operators
  // = equals, += Add and assign, a+=b same as a = a+b, same for -=, *=, /=, %=, Can also assign= bitwise operators
  
  //Relational Operators
  // == (5 == 10) false, != (5 != 10) true, > (5 > 10 ) false, < (5 < 10) true, >= (10 >= 10) true, <= (5 <= 10) true
  logResult = c == d; // is the value of c equal to the value of d, 5 not equal None, returns false
  printf("\nResult of == is %i\n", logResult);

  // Return statement;
  return 0;
}
