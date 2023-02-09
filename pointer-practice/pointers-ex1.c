// Write a program in C to show the basic declaration of pointer.

#include <stdio.h>

int main () {
  int m = 10;
  int n;
  int o;
  int *z;
  
  z = &m;
  
  printf("Pointers: Show the basic declaration of a pointer\n");
  printf("--------------------------------------------------\n");
  printf("Here is m=10, n and o are two integer variables and *z is an integer pointer\n");
  printf("\n");
  printf("z stores the address of m = %p\n", z);
  printf("\n");
  printf("*z stores the value of m = %i\n", *z);
  printf("\n");
  printf("&m stores the address of m = %p\n", &m);
  printf("\n");
  printf("&n stores the address of n = %p\n", &n);
  printf("\n");
  printf("&o stores the address of o = %p\n", &o);
  printf("\n");
  printf("&z stores the address of z = %p\n", &z);
  
  
  return 0;
}
