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
  
Assign Initial Values
  datatype array_name[size] = { element1, element2, .....element n };
  int counter[5] = {0, 1, 2, 3, 4};
  if you specify the array size and only initialize some of the elements then the remaining elements are set to 0
  C99 Compiler feature - Designated initializers
    float numbers[10] = {[2] = 100.1, [5]=50.7}
  Repeating an initial value
    Easiest thing to do is use a loop
    No way to do this in C89 and C99
    In C11 there is a way, need to learn more about this
******************************************
Multidimensional Arrays - (Like a nested list in python)
  Two dimensional array - matrix, table, rows and columns
  datatype name[size][size]
  int matrix[4][5]
  Above example represents a matrix with 4 rows and 5 columns for a total of 20 elements
  Each dimension is between its own pair of square brackets
  do not have to initialize all elements, all uninitialized will be set to 0, (have to provide inner braces in this case)
  can use designated initalizers with multi-dim arrays
  
  Initializing a 2 diminsional array - inner brackets are not required but improve readability
    datatype name[dimension 1 size][dimension 2 size] = {
    { row 1 element 1, element2,....element n},
    { row 2 element 1, element2,....element n},
    .
    .
    { row n element 1, element2,....element n}};
*****************************************    
Variable Length Arrays (VLA) - Not fixed size
  Does not mean that you can modify the length of the array after you create it
  keeps the same size after creation
  specify the size of an array with a varriable
  
******************************************/
#include <stdio.h>

#define MONTHS 12

int main() {
//   general arrays example
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
  
//   initialized array example - Variable Length Array example
  int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
  
  for (int i = 0; i < MONTHS; i++) {
    printf("Month %d has %2d days.\n", i + 1, days[i]);
  }
  
//   designated initializer example
  int days2[MONTHS] = {31, 28, [4]=31, 30, 31, [1] = 29};
  
  for (int i = 0; i < MONTHS; i++){
    printf("%2d %d\n", i + 1, days2[i]);
  }
  
  return 0;
}
