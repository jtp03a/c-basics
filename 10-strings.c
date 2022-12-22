/*****************************************
 * Notes - Strings
 * Anything between double quotes in C is interpreted by the compiler as a String
 * To use "" in a string use the \ escape like so \"
 * Likewise to use \ in string use \ escape like so \\
 * Null Character
 *  A special character with the code value is added to the end of each string to mark where it ends \0
 *  A string is always terminated by a null character, so the length of a string is always one greater 
 *  than the number of characters in the string
 *  Dont confuse the null chracter with NULL
 *    NULL is a symbol that represents a memory address that doesnt reference anything
 * 
 * Character Strings
 *  C has no special variable type for strings
 *  There are no special operators for processing strings
 *  The standard library provides an extensive range of functions to handle strings
 *  Strings in C are stored in an array of type char
 *  Characters in a string are stored in adjacent memory cells, one character per cell
 * 
 *  Declare a String
 *    char myString[20]; - Can accomodate a string that contains up to 19 characters (must allow one elmeent for the termination character (aka null character))
 *  Initialize a String
 *    char word[] = {'H', 'e', 'l', 'l', 'o'};
 *    If you dont specify the size the C compiler automatically computes the number of elements in the array and automatically addds the null terminator
 *    Best practice is to let the compiler automatically compute the size
 *    char word[] = "Hello!"; 
 * ***************************************/

#include <stdio.h>

int main() {
  // The null character here terminates output of everything after it
  printf("This string gets terminated early \0 because of the null character");

  
  return 0;
}