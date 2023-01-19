/******************************
 * Notes - Pointers - Pass by Value/Pass by reference
 * A few different ways to pass data to function
 *  Pass by value - when a function COPIES the actual value of an argument into the formal paramaters of function
 *    changes made to the parameter inside the function have no effect on the argument
 *  Pass by Reference - when a fucntion copies the address of an argument into the formal parameter
 *    changes made to the parameter affected actual passed argument    
 * ****************************/

// pass by value example

#include <stdio.h>

void swapByValue(int x, int y);
void swapByRef(int * x, int * y);

void swapByValue(int x, int y) {
  int temp;

  temp = x; // save the value of x into temp

  // printf("The value of temp is: %d\n", temp);
  // printf("The value of x is: %d\n", x);
  // printf("The value of y is: %d\n", y);

  x = y; // put y into x

  y = temp; //put temp into y

  // printf("The value of temp is: %d\n", temp);
  // printf("The value of x is: %d\n", x);
  // printf("The value of y is: %d\n", y);

  return;
}

// pass by reference example
void swapByRef(int * x, int * y) {
  int temp;

  temp = *x;

  *x = *y;

  *y = temp;

  return;
}


int main(void) {

  // pass by value example
  int a = 100;
  int b = 200;

  printf("Before swap value of a: %d\n", a);
  printf("Before swap value of b: %d\n", b);

  // call swap function
  swapByValue(a, b);

  printf("After swap value of a: %d\n", a);
  printf("After swap value of b: %d\n", b);

  // pass by reference example
  swapByRef(&a, &b);

  printf("After swap by Reference value of a: %d\n", a);
  printf("After swap by Reference value of b: %d\n", b);

  return 0;
}