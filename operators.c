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
Bitwise Operators
  C offers bitwise logical and shift operators
  operate on bits in integer values
  & - AND - copies bit if exists in both operands
  | - OR - copy bit if it exists in either operand
  ^ - XOR - copy bit if it exits in one operand but not both
  ~ - Compliment
  << - Left Shift
  >> - Right Shift
  bit is a 0 or 1, 8 make up a byte
  Examples of use - characteristics of a person
    store whether a person is male or female with one bit
    use three other bits to specify whether the person can speak french, german, or italian
    another bit to record whether the person's salary is 50000 or more
    in 4 bits a lot of data has been stored
    most common integer size is 4 bytes - 32 bits
    Binary conversion - take each postion 2^the position number to get that position value
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
  
  //Bitwise operators
  unsigned int e = 60; // 0011 1100
  unsigned int f = 13; // 0000 1101
  
  int bwResult = 0;
  
  bwResult = e & f; //returns 0000 1100 - 12
  printf("Bitwise AND result of 60 and 13 is: %d/n", bwResult);
  
  bwResult = e | f; //returns 0011 1101 - 61
  printf("Bitwise OR result of 60 and 13 is: %d/n", bwResult);
  
  bwResult = e ^ f; //returns 0011 0001 - 49
  printf("Bitwise XOR result of 60 and 13 is: %d/n", bwResult);
  
  bwResult = ~e; //returns -61
  printf("Bitwise Compliment result of 60 is: %d/n", bwResult);
  
  // Return statement;
  return 0;
}
