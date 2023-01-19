#include <stdio.h>

void calcSqNum(int * num); //declare a function that takes a pointer to an int

void calcSqNum(int * num) {
  *num = *num * *num; //square the value pointed to by the num pointer
}

int main() {
  
  int numtoSq = 5; 
  
  calcSqNum(&numtoSq); //pass the memory address of numtoSq to the function
  
  printf("%d", numtoSq); //shows that the value outside a function was modified by the function
  
  return 0;
}
