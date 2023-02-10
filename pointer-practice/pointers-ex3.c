// a program to add numbers using call by reference.
#include <stdio.h>

int sumNums(int *num1, int *num2, int *sum);

int sumNums(int *num1, int *num2, int *sum) {
   *sum = *num1 + *num2; 
}

int main() {
   int num1, num2, sum = 0;
   int *pNum1, *pNum2, *pSum = &sum;

   printf("Enter the first number: ");
   scanf("%i", &num1);
   printf("Enter the second number: ");
   scanf("%i", &num2);

   pNum1 = &num1;
   pNum2 = &num2;

   sumNums(pNum1, pNum2, pSum);

   printf("The sum of %i and %i is %i", num1, num2, sum);

   return 0;
}