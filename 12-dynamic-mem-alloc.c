/****************************************************
Notes - Dynamic Memory Allocation
  Whenever you define a variable in C, the compiler automatically allocates the correct amount of storage based on the data type
  Frequently desireable to be able to dynamicaly allocate storage while a program is running - allocate memory as needed
  Example:
    If you have a program that reads a set of data from a file into an array memory you can:
      define the array to contain the maximum number of possible elements at compile time
        int dataArray[1000]
          the datafile cannot contain more than 1000 elements, if it does there will be an issue
          if it is larger you must go back to the program, change size and recompile
      use a variable-length array to dimension the size of the array at runtime
        Not available until C-99, same problems as fixed length
      allocate the array dynamically using one of C's memory allocation routines
        enables allocation of memory as program is executing
  Dynamic Memory allocation depends on concept of pointer and provides strong incentive to use pointers in code
  Allocating data dynamically allows you to create pointers at runtime that are just large enought to hold the amount of data you require for a task (not wasting memory)
  Heap vs. Stack
    Dynamic Memory Allocation reserves space in a memory area called the heap
    You have to free memory on the heap
    Stack
      function arguments and local variables in a function stored in stack
      when execution of a function ends the space allocated to store arguements and local variables is freed
      
  
