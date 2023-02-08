/***********************************
Notes - File I/O
stdio.h is the header for file io
C views a file as a continuous sequence of bytes - each byte can be read individually
  corresponding to the file structure in the Unix environment
In C, a file has a beginning, and end, and a current position (defined as so many bytes from the beginning)
  current position is where any file action (read/write) will take place
  you can move the current position to any point in the file
Two types of files
  text - data written as a seq of characters organized as lines, each line ends with a new line 
    in windows/dos each line has a carriage return \r and a line feed \n but in linux only a \n
  binary - series of bytes exactly as they appear in memory
    image data, music encoding
Streams (can represent any type of input) - C programs automatically open three files on your behalf
  standard input - the normal input device for the system, i.e. keyboard - getchar(), scanf()
  standard output - usually the display screen - putchar(), put(), printf()
  standard error - usually the display screen - 
C library provides functions for reading and writing to or from data streams

Accessing files

  A program refrences a file through a file pointer or a stream pointer
  associate a file pointer with a file programmatically when program is run
  pointers can be reused to point to different files on different occasions
  a file pointer points to a struct of type FILE that represents a stream
    contains information like:
      whether you want to read or write or update the file
      address of teh buffer in memory to be used for data
      a poniter to the current position in the file for the next operation
      to use several files simultaneously, need a seperate file pointer
      
  Opening a File - fopen()
    associate a specific external file name with an internal file pointer
    fopen() returns the file pointer for a specific external file
    
    FILE *fopen(const char * restrict name, const char * restrict mode);
        first argument is a pointer to a string that is the name of the file
        can specify the name explicitly or use a char pointer that contains the address of the character string that is the file name
        can obtain the file name through CLI, input from user or defined constants
        
        second argument is character string that represents the file mode (read, write, append)
        
        fopen returns the file pointer if successfull or NULL if not
        
    File Modes
      w - open a text file for write operations. if the file exists, its current contents are discarded
      a - open a text file for append operations. all writes are to the end of the file
      r - open a fext file for read operations
      w+ - open a text file for updating (reading and writing) first truncating the file to zero length if it exists or created file if it does not
      a+ - open a text file for updating (reading and writing) appending to the end of the existing file or creating if the file doenst exist
      r+ - open a text file for updating (reading and writing)
      
    Example 
      FILE *pfile = NULL;
      char *filename = "myfile.text";
      pfile = fopen(filename, "w");
      
    if you only provide file name without path specification, file is assumed to be in the current directory
      you can specify a string that is the absolute or relative path
      
      For windows file paths must use \\ between directories, Linux uses /
      
    Rename a File - rename()
      rename(oldname, newname)
      returns 0 if success nonzero otherwise
      
      if(rename(oldname, newname)
        printf("Success");
      else
        printf("Failure);
        
    Close a file - fclose()
      use fclose() when finished with a fie to free up the file
      takes file pointer as the argument
      returns End of File (EOF) int if error occurs - special character usually -1
      0 if successful
      
      fclose(pfile);
      pfile = NULL;
      
      thread safe
    
    Delete a file - remove()
      remove(name of file)
      file cannot be currently open
      
    Reading from a text file
      fgetc() - reads a single character from a text file that has been opened for reading
      takes a file pointer an  returns character read as type int
      
      int mchar = fgetc(pfile);
      
      rewind() positions the file pointer to the beggining
      
      fgets() - read from any file or stream
        char *fgets(char *str, int nchars, FILE *stream)
        reads a string into memeory pionted to by a str from the file stream
        reads until encouters a \n or nchars-1, whichever occurs first
        if a newline character is read its retained in teh string
        a '\0' will be appeneded to the end of teh str
        if no error fgets() returns the pointer, tr
        if error NULL returned
        reading EOF causes NULL to be returned
        
        
  
    
************************************/

#include <stdio.h>

int main() {
  //read char from file
  FILE *fPntr;
  int c;
  char str[60];
  
  fPntr = fopen("file.txt", "r");
  
  if (fPntr == NULL) {
    perror("Error opening file");
    return(-1);
  }
  
  //read single char from file
  while((c=fgetc(fPntr)) != EOF) {
    printf("%c", c);
  }
  
  //read a string
  if(fgets(str, 60, fPntr)!=NULL) {
    printf("%s", str);
  }
  
  fclose(fPntr);
  fPntr = NULL;
 
  return 0;
}
