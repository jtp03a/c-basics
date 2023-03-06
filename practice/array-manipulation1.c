//Demonstrates pointer arithmetic, bubble sort, passing arrays to functions

#include <stdio.h>

int arrayManipulate(int *arr, unsigned int size);

int arrayManipulate(int *arr, unsigned int size) {
  printf("The address of arr is: %p, it points to the first value in the array: Exp 1: Result: %d\n", arr, *arr);
  
  int *ptr;
  int * const arrEnd = arr + size;
  
   //manipulate according to the rules
  for(ptr = arr; ptr < arrEnd; ptr++){
      if (*ptr % 2 == 0 && *ptr > 6) {
          *ptr *= *ptr;
      } else if (*ptr % 2 != 0 || *ptr > 2) {
          *ptr *= 2;
      }
  }
  
  int i, j, t;
  
  ptr = arr;
  
  //sort the function
  for (i = 0; i < size - 1; i++) { 
  
        for (j = 0; j < size - i -1; j++) { 
  
            if (*(ptr + j) > *(ptr + (j+1))) { 
  
                t = *(ptr + j); 
                *(ptr + j) = *(ptr + (j+1)); 
                *(ptr + (j+1)) = t; 
            } 
        } 
  } 
  
  //return the middle value
  int middle = size / 2; 
  
  if (size % 2 == 0) {
      int sum = 0;
      
      sum = *(arr + middle) + *(arr + (middle - 1));
      
      return sum;
  } else {
      return *(arr + middle);
  }
}

int main(){
  
  int arr[] = { 1, 4, 5, 12, 15};
  
  int arrLen = sizeof(arr) / sizeof(arr[0]);
  
  int result = arrayManipulate(arr, arrLen);
  
  printf("%d\n", result);
  
  for(int i = 0; i < arrLen; i++) {
      printf("%d ", arr[i]);
  }
  
  return 0;
}

