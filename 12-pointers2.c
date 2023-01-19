/*************************************
 * Notes - Use Case for Pointers
 * Assign Address to Pointer
 * Dereference a Pointer
 * Get the Pointer Address
 * Pointer Arithmetic
 *  Add, subtract, difference of two pointers
 *  Relational comparison
 * Array operations
 * 
 * Scanf - If you have a pointer already for a variable you can use the pointer name in scanf instead of 
 *  the & address of operator with the variable name.
 *  i.e:
 *  int value = 0;
 *  int * pvalue = &value;
 *  scanf("%d", pvalue);
 * 
 * Testing for NULL
 *  do not dereference an unitialized pointer
 *  int * pt; pointer pt is declared but not initalized
 *  *pt = 5; pt is deferenced and value of whatever pt is pointing to is set to 5
 *  pt wasnt initialized so it has a random memory address
 *  5 might go somewhere harmless or it might overwrite other data in memory causing a crash
 *  you can test for null with == NULL or if(!pvalue)
 * 
 * Const and Pointers
 *  Should the value that the pointer points to be constant or should the value of the pointer (the memory address) be constant
 * 
 * Void Pointers
 *  type void is absence of any type
 *  a pointer of type void* can contain the address of a data item of any time
 *  often used as a parameter type or return value type with functions that deal with data in a type independent way
 *  cannot be dereferenced directly bc it doesnt know what type of object it is pointing to
 *  void pointer must be explicitly cast to another pointer type before it is dereferenced
 * 
 * Pointers and Arrays
 *  one of the most common uses of pointers in C is as pointers to arrays
 *    main reason for using pointers to arrays is for notational convenience and program efficiency
 *  You do not need the & address of operator when initializing the pointer bc under the hood
 *  arrays are already pointers
 *  i.e.
 *  int values[100];
 *  int * valuesPtr = values; sets the pointer to point to the first value in the array, equivalent to valuesPtr = &values[0]
 
 * Pointer Arithmetic - incrementation or decrementation on a pointer
    used to iterate through the elements of an array
    *(valuesPtr + 3) will give the 4th element in the array (0 + 3) 0, 1, 2, 3
    *(valuesPtr + i) can be used to access the value contained in values[i]
    values[10] = 27; == *(valuesPtr + 10) = 27;
    since valuesPtr == values[0] by default you can set it to values[1] incrementing valuesPtr 1, valuesPtr += 1 or ++valuesPtr;
    be mindful or out of bounds errors
    
   Pointer Notation:
    When passing an array to a function the parameter can either be in array notation i.e:
     int arraySum (int array[], const int n);
    or can be in pointer notation, i.e.:
     int arraySum (int * array, const int n);
    Best practice: if you are going to be using index numbers to reference the elements of the array declare parameter in array notation
     if you are going to be iterating through the array with pointer arithmetic use the pointer notation
     
     Pointer notation Example:
     int arraySum (int * array, const int n);

  int arraySum (int * array, const int n) {
    int sum = 0;
    int * const arrayEnd = array + n;
    printf("The arrayEnd value is: %p\n", arrayEnd);
    printf("the address of array[0] is: %p\n", &array[0]);
    
    for (; array < arrayEnd; ++array ) {
      sum += *array;
    }
    
    return sum;
  }

int main()
{

  int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};
  
  printf("The sum is %i\n", arraySum(values, 10));

    return 0;
}
    
    
    
 * ***********************************/

#include <stddef.h>
#include <stdio.h>

int main(void) {
  long num1 = 0L;
  long num2 = 0L;
  long * pnum = NULL;

  pnum = &num1; //pnum points to the value num1 0
  *pnum = 2L; //the value pointed to by pnum, 0, gets sets to 2 so num1 is now 2
  ++num2; //num2 is incremented by 1 so num2 is now 1 
  num2 += *pnum; //num2 gets added to by the value pointed to by pnum, which is num1 which is 2 so num2 is now 3

  pnum = &num2; //the pointer pnum is now pointing to num2
  ++*pnum; //the value that pnum is pointing to which is the value of num2 gets incremented by 1 so num2 is now 4

  printf("num1 = %ld, num2 = %ld, *pnum = %ld, *pnum + num = %ld\n", num1, num2, *pnum, *pnum + num2); //num1 is 2, num2 is 4, *pnum is 4, *pnum + num2 is 4 + 4 = 8

  // scanf
  int svalue = 0;
  int * psvalue = &svalue;
  scanf("%d", psvalue);

  //const and pointers
  // value pointed to cannot be changed through derefrencing - *pvalue = something will produce and error but value = something will not, the pointer itself is not constant so pvalue = &something will work
  long lvalue = 9999L;
  const long * plvalue = &lvalue;

  // address stored in pointer cannot be changed - pcount = &something will produce an error
  int count = 43;
  int * const pcount = &count;

  // constant pointer that points to a value that is also constant
  int num3 = 25;
  const int * const pnum3 = &num3;
  
  // void* example
  int i = 10;
  float f = 2.34;
  char ch = 'k';

  void * vptr = NULL;

  vptr = &i;

  printf("Value of i = %d\n", *(int *)vptr);

  vptr = &f;

  printf("Value of i = %.2f\n", *(float *)vptr);

  vptr = &ch;

  printf("Value of i = %c\n", *(char *)vptr);

  //pointer arithmetic, sum all elements in an array
  int arraySum (int array[], const int n);
    
  int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};
  
  printf("The sum is %i\n", arraySum(values, 10));
 
}

// array notation example
int arraySum (int array[], const int n) {
  int sum = 0, *ptr; //declare a int sum variable and an int pointer
  int * const arrayEnd = array + n; //declare a pointer with a constant memory address and initialize it to the address which is the first element + n
  printf("The arrayEnd value is: %p\n", arrayEnd);
  printf("the address of array[0] is: %p\n", &array[0]);
  for (ptr = array; ptr < arrayEnd; ++ptr ) { // set ptr to the first element of array and increment the pointer ptr by one as long as it is less than the array End pointer
   printf("The address of ptr is: %p\n", ptr);
   printf("The value at the current pointer is: %d\n", *ptr);
   printf("The value of the next address is %p\n", ptr + 1); 
   sum += *ptr; //dereference the value of ptr to add on to sum
  }

  return sum;
}
