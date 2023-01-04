/****************************************
Notes:
- Indirection
  In programming, The ability to reference something using a name, reference, or container, instead of the value itself
  Using variable names is a form of indirection
  Manipulating a value through its memory address is a form of indirection
  A pointer provides an indirect means of accessing the value of a data item
    It is a variable whose value is a memory address
    its value is the address of another location in memory that can contain a value
  
- Must specifiy data type associatd with pointer so that it can know how much memory to allocate
  - It can only be used to point to variables of that data type
  - i.e. Pointer of type "pointer to int" can only point to variables of type int

- Why use pointers
  can treat any position of memmory as a variable
  easier to use arrays and strings
  refer to the same space in memory from multiple locations
    update memory in one location of program and see change in another location in program
  save memory space by being able to share components in data structures
  allow functions to modify data passed to them and have the change be reflected outside function (pass by reference)
  allows functions to return more than one value
  dynamic memory allocation
  design and develop complex data structures (stack, queue, linked list)
  direct memory access (effiecient and fast)
 
- Definining Pointers
  <Data Type> *<Name>
  Examples:
  int * pnumber //can store the address of any variable of type int
  char * pchar
  float * pf, * pg
  The space between the * and the pointer name is optional but best practice is to use the splace in declaration and omit it when derefrencing
  %p is the format specifier for pointers
  always initialize a pointer when you declare it
    if you cant then set it to NULL
      NULL
        a constant that is defined in the standard library (#include stddef.h)
        equivalent of 0 for a pointer
        gaurenteed to not point to any location in memory
        implicitly prevents the accidental overwriting of memory by using a pointer that does not point to anything specific (bufferoverflow, writing to memory you shouldnt)
        
- Address of operator
  & - used to initialize pointer with the address of a variable already declared
  Example:
  int number = 99;
  int * pnumber = &number;
  the declaration of the variable must proceed the declaration of a pointer to that variable
    cant assign a pointer to something that doenst have memory allocated
  can declare regular variables and pointers in the same statement
    double value, * pvalue = 1.00, &value
  
- Accessing Pointers
  * - Indirection operator/dereference operator
    dereferencing - accessing the value of the variable pointed to by a pointer
  Example:
    int number = 15;
    int * pnumber = &number;
    int result = 0;
    result = *pnumber + 5;
    
- Pointer memory
  Pointers occupy 8 bytes and the addresses have 16 hexadecimal digits
    if a machine has a 64-bit os and compiler supports 64-bit addresses
    some compilers only support 32-bit addressing in which case addresses with be 32-bit addresses
  
****************************************/

int main(void) {
  // defrefrencing example
  int count = 10, x;
  int * pcount = &count;
  x = *pcount;
  
  printf("count = %i, x = %i\n", count, x);
    
  //display pointers value - the memory address of the variable the pointer is pointing to
  printf("the value of the pointer pcount is %p\n", pcount);
  
  //display the memory address of the variable count, should be the same address when using the addresss of operator directly on the variable
  printf("the memory address of the variable count is %p\n", &count);
  
  //display the memory of address of the pointer - use the & - address of operator, (void*) prevent compiler warning, cast to void
  printf("the memory addresss of the pcount pointer is %p\n", (void*)&pcount);
  
  //display the number of bytes a pointer occupies
  printf("the memory size of pcount is %d bytes\n", (int)sizeof(pcount));
  
  //display the value of the variable that the pointer is pointing to - dereference operator
  printf("the value of variable that the pointer pcount is pointing to is %d\n", *pcount);
  
  return 0;
}
