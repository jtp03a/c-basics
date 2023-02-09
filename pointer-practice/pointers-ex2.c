// Write a program in C to add two numbers using pointers.

#include <stdio.h>

int main(){
  int num1;
  int num2;
  int *pNum1;
  int *pNum2;
  int sum;
    
  printf("Test Data: \n");
  
  printf("Input the first number: ");
  scanf("%i", &num1);
  printf("Input the second number: ");
  scanf("%i", &num2);
  
  pNum1 = &num1;
  pNum2 = &num2;
  
  sum = *pNum1 + *pNum2;
  
  printf("The sum of the entered numbers is : %i\n", sum);
  
  return 0;
}
