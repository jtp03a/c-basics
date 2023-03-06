#include <stdio.h>
#include <string.h>

int bitwiseOps(const char *first, const char *second);
int binToDec(const char *s);

int bitwiseOps(const char *first, const char *second) {
    if ((strlen(first) != 16 || strlen(second) != 16)) {
        return -1;
    }
    
    
    int decFirst = binToDec(first);
    int decSecond = binToDec(second);
    
    printf("DEBUG: first: %d\n", decFirst);
    printf("DEBUG: second: %d\n", decSecond);
    
    int result;
    
    if (decFirst % 2 == 0 && decSecond % 2 == 0) {
        result = decFirst & decSecond;
    } else if (decFirst % 2 != 0 && decSecond %2 != 0) {
        result = decFirst | decSecond;
    } else if (decFirst > 255 && decSecond > 255) {
        result = decFirst ^ decSecond;
    } else {
        result = decFirst + decSecond;
    }
  
  return result;
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
  char first[] = "0000000000000001";
  char second[] = "0000000110001011";
  
  int result = bitwiseOps(first, second);
  
  printf("The result of the bitwise operations on first and second is: %d\n", result);
  
  return 0;
}
