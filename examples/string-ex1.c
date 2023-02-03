#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int countChars(char str[]);
char concatStr(char str1[], char str2[], char result[]);

int countChars(char str[]) {
  int count = 0;
  
  for (; str[count] != '\0';count++);
  
    return count;
}

char concatStr(char str1[], char str2[], char result[]) {
  return result = *str1 + *str2;
}

int main() {
  
  char testString[] = "Test";
  char testString2[] = "anotherString";
  char result[100];
   
  printf("The string %s has % i characters in it.\n", testString, countChars(testString));
  printf("The result of concatenation between %s and %s is %s.\n", testString, testString2, concatStr(testString1, testString2, result));

  return 0;
}
