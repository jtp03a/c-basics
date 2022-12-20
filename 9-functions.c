/**************************************************
 * Notes - Fuctions
 * Tips
 *  Keep functions small and scoped to independent tasks
 *  Think of function as a black box, think about inputs and outputs
 * 
 * Benefits
 *  Use to reduce code duplication
 *  Add modularity/reusability to program
 *  improves readability
 *  improves program organization
 *  divide and conquer approach
 * 
 * Main Function
 *  specially recognized name in C
 *  All C programs must have main function
 *  can pass data to it via command line arguments (See 5-variables-datatypes-mem.c for example)
 *  return data optional (error codes)
 * 
 * Defining a Function
 *  function header - name of function, parameters (number and type of values passed to function when invoked), return type
 *    Choose meaningful function names - i.e. based on what its going to do
 *    If there are no statements in the body of a function the return type must be void
 *    Naming
 *      cant have two functions with same name
 *      cant have same name as standard library functions
 *      cant use reserved words (i.e. int double)
 *      first character must be a letter
 *  function body - statements that are executed when the function is invoked.
 *    has access to any values that are passed as arguments
 *    must always be surrounded by curly braces
 *  
 *  function header {
 *    function body
 *  }
 * 
 *  Return_type Function_name( Parameters - separated by commas ) {
 *    Statements;
 *  }
 * 
 * Declaring a Function - Function Prototype
 *  A function prototype is a statement that defines a function
 *  it defines the name, return value type, and the value type of each parameter
 *  provides all the external specifications for the function
 *  enables the compiler to generate the appropriate instructions at each point where you call the function
 *  checks that the function is being used correctly at each invocation
 *  generally appear at the beginning of a source file prior to the implementations of any functions or in a header file
 *  allows the function implementation to be invoked anywhere in the code regardless of where the function is placed in the file
 *  good practice to include function declarations for all functions in a program at the top 
 *  
 *  Return_type Function_name( Parameter_types );
 * 
 * Arguments and Parameters
 *  A parameter is a variable in a function declaration and function definition/implementation
 *  When a function is invoked the arguments are the data you pass into the function parameters
 *  means to pass data to a function
 *  names of the parameters are local to the function
 *  Passing Arrays to functions as arguments
 *    must pass additional argument specifiying the size of the array
 *    function has no means of knowing how many elements there are in an array
 *    
 *  
 *  add(1, 2) - Arguments
 *  int add(int x, int y) - Parameters
 * 
 * Returning
 *  specify the type of the value to be returned as any of the legal types in C
 *  can return void which means nothing is being returned
 *  a function that has statements in the function body but does not return a value must have the return type as void
 *  a function that does not have a void return type must return a value of teh specified return type
 *  if the return express reults in a value with a different return type from the specified type the compiler will try and convert it if it can, if it cant there will be an error
 *  you can have more than one return statement
 *  Return statement
 *    return expression;
 * 
 * Invoking a function
 *  the arguments you specify when you invoke a function should agree in type, number and sequence with the function header
 *  use the function on the right side of an assignement statement to assign the return value
 * 
 *  int x = myFunctionCall()
 * 
 * Local and Global Variables - Function/Program Scope
 *  Local
 *    variables defined inside a function are known as automatic local variables
 *    automatically created each time the function is called
 *    values are local to the function
 *    the value of a local variable can only be accessed bye the function in which the variable is defined
 *    i.e it cannot be accessed by another function
 *    if an initial value is given to a variable inside a function that inital value is assigned to the variable each time the function is called
 *    static keyword can be used to keep the value of the variable
 *    can use the auto keyword to be more precise but the compiler adds this by default
 *    local variables applicable to any code where the variable is created in a block (i.e. loops, if statements)
 *  
 *  Global
 *    can be acessed by any function in the program
 *    has the lifetime of the program
 *    declared outside the function and do not belong to any particular function
 *    an function in the program can change the value of a global variable
 *    a local variable with the same name as global variable will take precedence and the global variable will not be accessible.
 *    Reasons to Avoid Global Variables
 *      Promotes coupling between functions - dependencies 
 *      makes debugging harder
 *    In general if a function needs access to data pass through a parameter instead of a global variable
 * ************************************************/
#include <stdio.h>

// global variable
int myGlobal = 0;

// function declaration
int multiplyTwoNumbers(int x, int y);

int main() {
  // function invocation
  int result1 = multiplyTwoNumbers(5, 10);
  int result2 = multiplyTwoNumbers(2, 4);
  int result3 = multiplyTwoNumbers(10, 20);

  printf("%d %d %d\n", result1, result2, result3);
  
  return 0;
}

// function implementation/definition
int multiplyTwoNumbers(int x, int y) {
  // local variable
  int result = x * y;
  printf("The product of %d multiplied by %d is %d\n", x, y, result);
  return result;
}