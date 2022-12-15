/******************************************
Notes - Arrays
Delcaring Arrays in C
  items in C array are elements
  elements in C array have to be the same type
  
  datatype array_name[num of elements]
Array elements accessed by index like other languages starting at index 0
Off-by-one error - assuming that arrays start from one
Out-of-bounds error - trying to access an index value that is outside of range for the array
  produces unpredicable results because the compiler cannot check for out-of-bounds error so program
  will still compile

Assigning values to Array
  array[index] = value;
******************************************/
#include <stdio.h>

int main() {
  int grades[10];
  int count = 10;
  long sum = 0;
  float average = 0.0f;
  
  printf("\nEnter the 10 grades:\n");
  
  for(int i = 0; i < count; i++) {
    printf("%d> ", i + 1);
    scanf("%d", &grades[i]);
    sum += grades[i];
  }
  
  average = (float)sum/count;
  
  printf("\nAverage of the ten grades entered is: %.2f\n", average);
  
  return 0;
}
