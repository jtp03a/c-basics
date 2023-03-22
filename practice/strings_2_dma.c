
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Include any needed headers

int haystack_needle(char *haystack, char *needle);
int main()
{
    char string[] = "This is my brand new sentence";
    char substring[] = " brand new";
    // TODO: make the call to modify the string
    haystack_needle(string, substring);

    // TODO: Print out the modified string
    printf("The new string is: %s\n", string);

    return 0;
}

/*
Arguments:
-haystack --- pointer to string to search
-needle   --- pointer to substring to search inside of haystack

PURPOSE:
haystack_needle takes the arguments above and searches the haystack
for the needle. Once it finds the needle... it removes it from the haystack.

Return:
return 0 on success
return -1 on error
*/
int haystack_needle(char *haystack, char *needle)

{
    /*
    TODO: Using strstr() find the needle in the haystack (substring in string)
    the pointer that is returned is pointing to the substring within the string 
    Set that pointer to a new char pointer called *mark_position
    */
    char *mark_position = strstr(haystack, needle);

    // TODO: Check to see if the needle is in the haystack and return error if not
    if (mark_position == NULL) {
        return -1;
    }
    
    int needleLength = strlen(needle);

    // TODO: Create a char buffer named *buffer using malloc \
    ensure it is large enough to hold string[] + a nul-terminator
    char *buffer = (char*)malloc(100);

    // TODO: Ensure buffer was created
    if (buffer == NULL) {
        return -1;
    }

    /*
    TODO: Using strcpy(), store the end of the haystack into the buffer...
    you are not authorized to use the variable needle.
    */
    buffer = strcpy(buffer, mark_position + needleLength);
    
    printf("val of buffer: %s\n", buffer);

    /*
    TODO: Using memmove, overwrite the haystack (string)... effectively removing the needle 
    HINT: start at the mark_position... that is after all where we need to start replacing.
    */
    memmove(mark_position, buffer, strlen(buffer) + 1);

    // TODO: Give back the memory from buffer
    free(buffer);

    return 0;
}
