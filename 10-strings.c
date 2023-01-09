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

  Constant Strings
   #define preprocessor directive is used to set constants
    #define TAXRATE 0.015 - no assignment operator, no semicolon
    define can appear anywhere in the program but best practice is to put them at the beginning of the file
    can be used for characters and strings
    C90 added const modifer for variables
     i.e. const int MONTHS = 12;
    enums are a symbolic constant
    Prevent strcopy from modifing a string by using constant
     const char message[] = "This is a standard message."

   C String Functions - Add string.h as a header file
    strlen() - get the length of a string
      returned as a size_t (iterchangable with int)
    strcpy() and strncpy() - copy one chracter string to another
      strcpy function does not check to see wheter the source string actually fits in the target
      string
    strcat() and strncat() - combining two character strings together (concatentation)
      takes two strings, copy of second is tacked onto end of first, second string is not altered
      returns the value of first argument
      strcat does not check to see whether the second string will fit in the first array
      if you fail to allocate enough space for the first array you will run into problems as excess characters overflow into adjecent memory
      strncat takes a second argument indicating the max number of characters to add
    strcmp() and strncmp() - determining if two character strings are equal
      cannot use == to compare strings, it only checks for same memory address
      strcmp compares string contents not string addresses
      does not compare arrays so it can be used to compare strings stored in arrays of different sizes
      does not compare characters, i.e cant compare "A" to 'A'
      returns 0 if two string arguments are teh same and nonzero
      returns value < 0 if str2 is less than str1
      returns value > 0 if str2 is greater than str1
 * ***************************************/

#include <stdio.h>
#include <string.h>

int main() {
    // The null character here terminates output of everything after it
    printf("This string gets terminated early \n\0 because of the null character");

    char str1[] = "To be or not to be"; //declare and initialize the string and let compiler compute size and add a null terminator
    char str2[] = ", that is the question";

    unsigned int count = 0;

    // demonstrates that the str is an array, there is a string length function to determine string length
    while (str1[count] != '\0') {
        ++count;
    }

    printf("The length of the string \"%s\" is %d characters. \n", str1, count);

    count = 0;

    while (str2[count] != '\0') {
        ++count;
    }

    printf("The lenght of the string \"%s\" is %d characters.\n", str2, count);

    //  strlen()
    char myString[] = "my string";

    printf("The length of this string is %d\n", strlen(myString));

    //  strcpy() - equivalent of the assignment operator for strings - does check if size is right
    char src[50], dest[50];

    strcpy(src, "This is source\n");
    strcpy(dest, "This is destination\n");
    //  strncpy() - safer than strcpy() bc it takes a 3rd argument as the max number of characters to copy
    char src1[40];
    char src2[12];

    memset(dest, '\0', sizeof(dest));
    strcpy(src, "Hello how are you doing\n");
    strncpy(dest, src, 10);

    char temp[50];

    // using size of as the 3d parameter will ensure that there are no bufferoverflows
    strncpy(temp, myString, sizeof(temp) - 1);
    printf("The string is: %s\n", temp);

    // string concatenation
    char catSrc[50], catDest[50];
    strcpy(catSrc, "This is source");
    strcpy(catDest, "This is destination");

    strncat(catDest, catSrc, 15);

    printf("Final destination string: |%s|\n", catDest);

    printf("strcmp(\"A\", \"A\") is ");
    printf("%d\n", strcmp("A", "A")); //returns 0

    printf("strcmp(\"A\", \"B\") is ");
    printf("%d\n", strcmp("A", "B")); //returns -1 - B is less than A

    printf("strcmp(\"B\", \"A\") is ");
    printf("%d\n", strcmp("B", "A")); //returns 1 - A is great than B

    printf("strcmp(\"Z\", \"a\") is ");
    printf("%d\n", strcmp("Z", "a")); //returns -1 - a is less than Z

    printf("strcmp(\"apples\", \"apples\") is ");
    printf("%d\n", strcmp("apples", "apples")); //returns 0
;
    return 0;

}
