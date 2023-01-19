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
      
  Malloc
    need to include stdlib.h
    specify the number of bytes of memory as argument to the function
    returns the address of the first byte of memory that is allocated, a pointer of type void
    because you get an address returned, a pointer is the only place to put it
    if memory requested cannot be allocated malloc() returns a pointer with the value NULL
    
    
    int * pNum = (int*)malloc(100)
    In the above example:
      pNum will point to the first int location at the beginning of the 100 bytes that were allocated
      if ints are 4 bytes each on this system then it can hold 25 int values
      best practice to use size of operator to ensure code is portable:
      int * pNum = (int*)malloc(25*sizeof(int));
      
      best practice to check with if statement to make sure memory is available when making a dynamic memory request
      if(!pNum) {
        statements to deal with memory allocation failure, display a message and terminate program
      }
      
    Releasing
      Memory that you allocate on the heap will be automatically released when your program ends but it is better to explicitly
      release the memory when you are done using it even if its just before exiting the program, cleaner and best practice
      ALWAYS RELEASE MEMORY IF ALLOCATED
      Memory Leak - when you allocate some memory dynamically and do not retain the reference to it so you are unable to release it.
        often occurs in a loop, becaue you do not relese the memory when it is no longer required your program consumes more and more
        available memory on each loop iteration and eventually causes a problem
        
      free(pNum);
      pNum = NULL;
      
      
  
  
      
  
