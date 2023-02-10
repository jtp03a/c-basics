#include <stdio.h>

int main() {
   int numElements;
   printf("Input the number of elements to store in the array: ");
   scanf("%i", &numElements);

   int numArr[numElements], *pNumArr = numArr;

   printf("Input %i elements into the array: \n", numElements);
   for (int i = 0; i < numElements; i++) {
      scanf("%i", pNumArr + i);
   }

   printf("The elements you entered are: \n");
   for (int i = 0; i < numElements; i++) {
      printf("element - %i : %i\n", i, *pNumArr + i);
   }
   
   return 0;
}