/****************************
 * Notes - Pointers and Strings
 * A common application of using a pointer to an array is as a pointer to
 * a character string
 *  often used to pass data to a function * 
 * **************************/

// Examples
#include <stdio.h>

void copyString (char * to, char * from);

void copyString (char * to, char * from) {
  while (*from) { //runs until it hits the null character which is 0 so causes while loop to end
    *to++ = *from++; //post incrementation, wont increment until after seting to equal to from
  }

  *to = '\0';
}

int main (void) {
  char string1[] = "Copy this string";
  char string2[50];

  copyString(string2, string1);

  printf("%s\n", string2);
  
  return 0;
}