#include <stdio.h>

int getStrLen(const char * string);

int getStrLen(const char * string) {
  const char * const start = string;
  
  while (*string != 0) {
    // printf("%p\n", string);
    string++;
  }

  return string - start;
}

int main(void) {

  printf("The length of the String is: %d\n", getStrLen(""));

  return 0;
}