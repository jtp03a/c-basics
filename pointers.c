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
 
 -
  

****************************************/
