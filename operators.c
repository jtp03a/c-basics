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
Cast and SizeOf
  Type conversions in C
    Implicit Conversion - conversion of data between differnt types that happens automtically
      Rules in C
        When implicit conversion happens data will be truncated (less precise) or promoted (more precise), can be useful in certain cases
        When a floating-point value is assigned to an int the decimal portion gets truncated
        When a in is assigned to a float there is no change to the value of the number
        Arithmetic
          ***If 2 operands in an expression are ints any decimal portion resulting from devision is discarded***
          ***if 1 operand is an int and the other is a float then the decimal is preserved***
    Explicit Conversion (Cast operator) - conversion of data between different types that programmer does
      Demand the precise type conversion you want
      precent the quantity with the name of the desired type in parentheses
      parentheses and type name together constitute a cast operator
      has a higher precedence than all arithmetic operators except the unary minus and plus
  sizeof
    can find out how many bytes are occupied in memory by a given type (special keyword of C)
    evaluated at compile time and not runtime unless a variable-length array is used in its argument
    argument of sizeof can be a variable, array name, name of basic data type, name of a derived datatype, or expression
    use sizeof to avoid having to calcuate and hardcode sizes into program (different sizes based on architecture)
  Misc operators:
    *variablename - derefrencing a pointer
      represents a pointer to a variable
    ?: - Ternary - If condition is true ? then value X : otherwise value Y
Operator Precedence in C
  operators have a precedence level that determines order of execution
  whatever is enclosed in parentheses is execute first
  Associativity if two operators have the same precedence
    for most operators the order is left to right - ex 1 == 2 != 3 returns true (1)
    unary goes right to left


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
  printf("Bitwise AND result of 60 and 13 is: %d\n", bwResult);
  
  bwResult = e | f; //returns 0011 1101 - 61
  printf("Bitwise OR result of 60 and 13 is: %d\n", bwResult);
  
  bwResult = e ^ f; //returns 0011 0001 - 49
  printf("Bitwise XOR result of 60 and 13 is: %d\n", bwResult);
  
  bwResult = ~e; //returns -61
  printf("Bitwise Compliment result of 60 is: %d\n", bwResult);

  bwResult = e << 2; // returns 1111 0000 - 240
  printf("Bitwise Left shift by 2 result of 60 is %d\n", bwResult);

  bwResult = e >> 4; // returns 0000 0011 - 3 - two bits get pushed off the end
  printf("Bitwise right shift by 4 result of 60 is %d\n", bwResult);

  // Casting
  int g = 0;
  float h = 12.125;

  g = h; //returns 12

  printf("When a float is cast into an int the decimal portion is lost: %d\n", g);

  float i = 21.51;
  float j = 26.99;

  printf("%d\n", (int)i + (int)j); //returns 47

  //sizeof
  printf("The size of an int is: %lu\n", sizeof(int));

  //asociatifity
  printf("%d\n", 1 == 2 != 3); //returns 1
  
  // Return statement;
  return 0;
}
