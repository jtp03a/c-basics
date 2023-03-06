#include <stdio.h>
#include <stdlib.h>

int ascending(int a, int b);
int descending(int a, int b);
int *bubbleSort(int elements[], size_t length, int (*compare)(int a, int b));

int ascending(int a, int b) {
  //printf("DEBUG: a: %d, b: %d\n", a, b);
  return a > b;
}

int descending(int a, int b) {
  return a < b;
}

int *bubbleSort(int elements[], size_t length, int (*compare)(int a, int b)) {
  int i , j;
  for (i = 0; i < length - 1; i++) {
    for (j = 0; j < length - i - 1; j++) {
      //check the current element and the next element against the comparator
      if (compare(elements[j], elements[j+1])) {
        //if the comparator returns true then swap the current element with the next one
        int temp = elements[j];
        elements[j] = elements[j+1];
        elements[j+1] = temp;
      }
    }
  }
  return elements;
}

int main () {
  
  int result = 0;
  
  //Tests
  result = ascending(10, 5);
  printf("Ascending, 10, 5, Exp: 1 (true): Result: %d\n", result);
  
  result = ascending(5, 10);
  printf("Ascending, 5, 10, Exp: 0 (false): Result: %d\n", result);
                     
  result = descending(5, 10);
  printf("Ascending, 5, 10, Exp: 1 (true): Result: %d\n", result);                   
                     
  result = descending(10, 5);
  printf("Ascending, 10, 5, Exp: 0 (false): Result: %d\n", result);
  
  int arr[] = {5, 1, 4, 2, 8};
  
  int (*pAscending)(int, int) = &ascending; //delcare and initialize function pointers
  int (*pDescending)(int, int) = &descending;
  
  size_t length = sizeof(arr) / sizeof(arr[0]); //get length of the array
  
  printf("length: %ld\n", length);

  int *pointer;
                                    
  pointer = bubbleSort(arr, length, ascending);
  
  printf("The pointer is pointing to the first element of the sorted array, Exp: 1: Result: %d\n", *pointer);
  
  for (int i = 0; i < length; i++, pointer++) {
    printf("%d ", *pointer);
  }
  printf("\n");
                     
  pointer = bubbleSort(arr, length, descending);
  
  printf("The pointer is pointing to the first element of the sorted array, Exp: 8: Result: %d\n", *pointer);

  for (int i = 0; i < length; i++, pointer++) {
    printf("%d ", *pointer);
  }
  printf("\n");

  return 0;
}
