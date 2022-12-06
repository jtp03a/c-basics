#include <stdio.h>

int main() {
  printf("Int size is: %lu\n", sizeof(int));
  printf("Char size is: %lu\n", sizeof(char));
  printf("Long size is: %lu\n", sizeof(long));
  printf("Long Long size is: %lu\n", sizeof(long long));
  printf("Float size is: %lu\n", sizeof(float));
  printf("Double size is: %lu\n", sizeof(double));
  printf("Long Double size is: %lu\n", sizeof(long double));
  printf("Short size is: %lu\n", sizeof(short));
  
  return 0;
}