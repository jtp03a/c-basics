#include <stdio.h>

int bitwiseOps(const char *first, const char *second);
int binToDec(const char *s);

int bitwiseOps(const char *first, const char *second) {
    int decFirst = binToDec(first);
    int decSecond = binToDec(second);
  
  return 0;
}

int binToDec(const char *s) {
  int total = 0;
  
  while(*s) {
        int num = (int)*s - '0';

        total = total * 2 + num;

        s++;
  }
  return total;
}


int main () {
  char first[] = "0000000000001111";
  char second[] = "000000000000101";
  
  int result = bitwiseOps(first, second);
  
  printf("The result of the bitwise operations on first and second is: %d\n", result);
  
  return 0;
}
