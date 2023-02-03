#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int countChars(char str[]);
void concatStr(const char str1[], const char str2[], char result[]);
bool compareStr(const char str1[], const char str2[]);

int countChars(char str[]) {
  int count = 0;
  
  for (; str[count] != '\0';count++);
  
    return count;
}

void concatStr(const char str1[], const char str2[], char result[]) {
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

bool compareStr(const char str1[], const char str2[]) {
    int str1len = countChars(str1);
    int str2len = countChars(str2);
    
    if (str1len != str2len) {
        return false;
    }
    
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
  
  char testString[] = "Test";
  char testString2[] = "Test";
  char result[100];
   
  printf("The string %s has % i characters in it.\n", testString, countChars(testString));
  concatStr(testString, testString2, result);
  printf("The result of concatenation between %s and %s is %s.\n", testString, testString2, result);
  
  printf("Is %s equal to %s: %s", testString, testString2, compareStr(testString, testString2) ? "True" : "False");
  return 0;
}
