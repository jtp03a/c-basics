//Write a program in C to find the maximum number between two numbers using a pointer.
#include <stdio.h>

int *maxNum(int *num1, int *num2);

int *maxNum(int *num1, int *num2){
   return *num1 > *num2 ? num1 : num2;
}

int main() {
   int num1, num2;

   printf("Input the first number: ");
   scanf("%i", &num1);
   printf("Input the second number: ");
   scanf("%i", &num2);

   int *result = maxNum(&num1, &num2);

   printf("%i is the maximum number", *result);

   return 0;
}