/**************************************************
Variables in Memory
  Think of RAM as an ordered sequence of boxes
  The box is full when it represents 1 or the box is empty when it represents 0
  each box represents one binary digit, either 0 or 1
  each box is called a bit
  bits in memory or grouped into sets of eight (byte)
  each byte has been labeled with a number (address)
  the address of a byte uniquely refrences that byte in computer memory
  ***BLUF: memory consists of a large number of bits that are in groups of eight (called bytes) each byte has a unique address
  Constants - Data type that does not change
  Variables - types of data that may change or assigned values as the program runs - stored in memory with an addresss
  Variables are the names you give to computer memory locations which are used to store values
C variables naming rules:
  must begin with letter or underscore, can be followed by an combination of letters upper and lower, underscores or digits, spaces
  cant use reserved words
  use meaningful names
Data Types - correspond to the byte size on the platform of you program
Primitive data types - not objects, all C data types are primitive. no objects in C
Process in C
  Declare - specify type followed by variable name followed by semicolon
  can declare more than on on single line with commo sep
  C requries all variables be declared before used
  assign by using =
  initialize - assign at start, can be done as part of the declaration
C Data Types
  int, non int numerical, characters - difference between types is the ammount of memory they occupy and the range of values
  they can hold, amount of memory depends on the platform architecure (ie x86, 64) might take up 32 bits vs 64 bits
  int - pos/neg integers, signed(pos, neg, 0), can be hex 0x, i.e. int rgbColor = 0xFFEF0D
    Other int types - short (save space), long (express larger values), unsigned (no negatives) adjectives
  float - floating point numbers, decimals, floating point constant in scientific notation 1.7e4
  double - float but roughly twice the precision, twice as many significant digits, often represented using 64 bits
    can explicitly express a float constant by appending f or F to the end of the number
  char - 
  _Bool - stores 0 or 1, true (1) or false (0), binary choice
Enum and Char
  Enum - a data type that allows specification of valid values that can be stored
    compiler treats enumseration identifiers as integer constants, first item in the list is 0, can explicity assign the integer
    value for the items in the enum, i.e. instead of 0, 1, 2, you could have 0, 1, 5, 6, 7, 10, 11 etc.
  Char
    represents a single char i.e. 'A', character literals use single quotes
    can declar to be unsigned -telling compiler it can only be positive, if its a char number
    different from strings (seq of chars)
    can use the ASCII value but is generally considered poor practice
  Escape Char/Special Chars
    can use sympol sequences
    enclosed in sing quotes
    \a - Alert
    \b - Backspace
    \f - Form feed
    \n - New line
    \r - carriage return
    \t - horizontal tab
    \v - verticle tab
    \\ - backslash
    \' - singe quote
    \" - doube quote
    \? - question mark
    \0oo - Octal value 
    \xhh - hex value
Format Specifiers
  used to display variables as output - specifiy type of data of variable want to display
  %i or % d - int
  %f - float
  %e or %g - double
  %c - char
  %i or %u - also bool (bools are really 0 or 1)
  %hi, %hx, %ho - short int
  %hu, %hx, %ho - unsigned short int
  %Lf - long double
  https://www.tutorialspoint.com/format-specifiers-in-c
Command Line Arguments
  arguments passed to the program at time program is executed
  every c program has a main() function which is the entry point for the program
  when main is called two arguments are passed to the function
    argc - argument counter - integer that specifies the # of args typed on the cmd line
    argv - argument vetcor - array of characters pointers
      first entry in the array is a pointer to the name of teh program that is executing
    
    
********************************************************/

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  //command line arugments examples
  int numberOfArguments = argc;
  char *argument1 = argv[0];
  char *argument2 = argv[1];
  
  printf("Number of Arguments: %d/n", numberOfArguments);
  printf("Argument 1 is the program name: %s/n", arugments1);
  printf("Argument 2 is the command line argument: %s/n", argument2);
  
  //basic variables examples
  int myAge = 36;
  unsigned int x = 5
  
  myAge = 36;
  
  float myFloat = 12.223;
  double myDouble = 33.4484858959;
  double sciNot = 55.559949e11;
  _Bool myBool = 1; //C89 standard
  bool myBoolean = true; //C99 standard, must include stdbool.h
  
  //enums examples
  enum myNums {1, 2, 3, 4, 5};
  enum gender {male, female}
  
  enum myNums myNum1, myNum2;
  
  enum gender myGender;
  
  myGender = male;
  
  enum gender otherGender = female;
  
  bool isMale = (myGender == otherGender) //returns False
       
  myNum1 = 1;
  myNum2 = 2;
  
  //char examples
  char myChar;
  myChar = 'T'; //must be single quotes, double quotes is for string
  
  char newLine = '\n';
  
  // printf and format specifiers examples
  int integerVar = 100;
  float floatVar = 331.38;
  double doubleVar = 8.44e+11;
  char charVar = 'W';
  _Bool boolVar = 0;
  
  printf("integerVar = %i\n", integerVar);
  printf("floatingVar = %f\n", floatVar);
  printf("doubleVar = %e\n", doubleVar);
  printf("charVar = %c\n", charVar);
  printf("boolVar = %i\n", boolVar);
  
  float a = 3.9923232323;
  printf("%.2f", a); //specifie precision 
  
    
  return 0;
}  
 
