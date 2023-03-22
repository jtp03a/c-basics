#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //TODO: Create a string containing your first name
    char name[] = "Jake";
    
    printf("val of: name: %s\n", name);

    //TODO: Get the size of this string
    int size = sizeof(name);
    printf("val of strlen: %d\n", strlen(name));
    
    printf("val of: size: %d\n", size);

    //TODO: Declare a char pointer *str
    char *str = NULL;

    //TODO: Allocate a section of memory of type char of 40 bytes, and...
    //TODO: Asign the address of this allocated space to the pointer value
    str = (char*)malloc(40);
    
    //TODO: Copy your name into the allocated space using strcpy()
    if (str == 0) {
        
    }
    
    strcpy(str, name);

    //TODO: Print out your name that is stored in the allocated memory space
    printf("val of: str: %s\n", str);

    //TODO: Reallocate the memory space using the size of the string rather than 40 bytes
    str = (char*)realloc(str, size * sizeof(char));

    //TODO: Print out the string again
    printf("val of: str after realloc: %s\n", str);
}
