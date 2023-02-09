#include <stdio.h>
#define FILENAME "test.txt"

//program to output the contents of  text file in reverse
int main()
{
    FILE *fPntr;
    int c;
    int len;
    
    fPntr = fopen(FILENAME, "r");
    
    if (fPntr != NULL) {
        fseek(fPntr, 0, SEEK_END);
        len = ftell(fPntr);
        for (int i = 0; len > 0; i--) {
            fseek(fPntr, i, SEEK_END);
            len = ftell(fPntr);
            printf("%c", fgetc(fPntr));
        }
    }
    printf("\n");
    
    fclose(fPntr);
    fPntr = NULL;
    
    return 0;
}
