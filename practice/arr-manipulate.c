#include <stdio.h>

int arrayManipulate(int *arr, unsigned int size);

int arrayManipulate(int *arr, unsigned int size) {
   
  return 0;
}

int main(){
  
  int arr[] = { 1, 5, 12 };
  
  int arrLen = sizeof(arr) / sizeof(arr[0]);
  
  int result = arrayManipulate(arr, arrLen);
  
  printf("%d\n", result);
  
  return 0;
}

