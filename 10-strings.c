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
 *    Since you can not assign arrays in C, you can not assign strings either
 *		i.e. char s[100; //declare
 *			 s = "hello; // initialize, this will produce an error
 *		You can use strncopy() to assign a value to a char array after it has been declared and initialized
 *		You can access each element in the string array by the index and assign
 *		i.e. s[0] = 'h';
 *		Best practice is to initialize the string when declaring with no specified size and then to use strncopy() if need to change
 *	
 *	Display a string
 *	  printf("\nThe message is: %s", message)
 *	  %s is the format specifier for outputting a null-terminated string
 
 *	Inputing a string
 *	  char input[10];
 *	  printf("Please input your name: ");
 *	  scanf("%s", input);
 *	  dont need to use the & on a string in scanf
    
    Testing if two strings have equality
      In C the equality operator cannot be applied to arrays and structures so it wont work with stringe either
        can use the strcmp function
        str constant "x" is not the same as character constant 'x'
 * ***************************************/

#include <stdio.h>

int main() {
    // The null character here terminates output of everything after it
    printf("This string gets terminated early \0 because of the null character");

    char str1[] = "To be or not to be"; //declare and initialize the string and let compiler compute size and add a null terminator
    char str2[] = ", that is the question";

    unsigned int count = 0;

    while (str1[count] != '\0') {
        ++count;
    }

    printf("The length of the string \"%s\" is %d characters. \n", str1, count);

    count = 0;

    while (str2[count] != '\0') {
        ++count;
    }

    printf("The lenght of the string \"%s\" is %d characters.\n", str2, count);
    return 0;
}
