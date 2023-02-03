#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int countChars(char str[]);
void concatStr(char str1[], char str2[], char result[]);

int countChars(char str[]) {
  int count = 0;
  
  for (; str[count] != '\0';count++);
  
    return count;
}

void concatStr(char str1[], char str2[], char result[]) {
  int currentPos = 0;
  for (int i = 0; str1[i] != '\0'; i++) {
    result[currentPos] = str1[i];
    currentPos++;
  }
 
  for (int i = 0;  str2[i] != '\0'; i++) {
    result[currentPos] = str2[i];
    currentPos++;
  }
}


int main() {
  
  char testString[] = "Test";
  char testString2[] = "anotherString";
  char result[100];
   
  printf("The string %s has % i characters in it.\n", testString, countChars(testString));
  concatStr(testString, testString2, result);
  printf("The result of concatenation between %s and %s is %s.\n", testString, testString2, result);

  return 0;
}
