/***************************************************************
 * Notes - Comments, Preprocessor, Input/Output
// Preprocessor, denoted with # - part of c compilation that recognizes special statements, analyzes these statements before analysis of the C 
// progress itself, instruction to compiler to do something before compiling 
// can be used to create constants and macros with #define
// include - library (reusing existing code) files
// conditionals - ifdef, endif, else, ifndef
// .h indicates a header file
// Header files - define information about some of the functions that are provided by that file
// i.e. stdio.h is the standard C library header provides functionality for displaying output among other tings
// header files specify information that the compiler ues to integrate any predefined functions within a program
// you can create your own header files for use within your program - header file names are casesensitive and best practice is to write them in all lowercase
// header files can either be surrounded in <> or "", double quote usually means user defined i.e. not part of the C library
// you can use the #ifndef and #define to protect against multiple inclusions of a header file
// executable code (no logic, just type definitions, structures, function prototype) normally goes in a source code file not a header fle, some exceptions
// In C there are 3 streams, standard in (keyboard by default), standard out, and error
// stdin and out use format specifiers:
// %s - string, %d - int, %c - char, %f - float
// for stdin - keyboard input is read as text, scanf converts chars to numbers
// scanf(control string, arguments - pointers to variables) - returns number of items it successfully reads, preceed the basic variable types with &, for string dont use & 
// printf(control string, arguments - variable names, constants, expressions)
// problems with scanf if you right multiple in a row
****************************************************************/

#include <stdio.h>

//single line comment
/* 
multiline 
comment 
*/

int main() {
  //output
  printf("Hi my name is Jake\n");
  //input
  char str[100];
  int i;
  double x;

  printf("Enter a value:");
  scanf("%s %d %lf", str, &i, &x);

  printf("\nYou entered: %s %d %lf", str, i, x);

  return 0;
}
