#include <stdio.h>
#include <stdlib.h>

int main() {
   int numElements;
   printf("Input the number of elements to store in the array: ");
   scanf("%i", &numElements);

   int *numArr = calloc(numElements, sizeof(int));

   printf("Input %i elements into the array: \n", numElements);
   for (int i = 0; i < numElements; i++) {
      scanf("%i", numArr + i);
   }

   printf("The elements you entered are: \n");
   for (int i = 0; i < numElements; i++) {
      printf("element - %i : %i\n", i, *numArr + i);
   }

   free(numArr);
   numArr = NULL;
   
   return 0;
}