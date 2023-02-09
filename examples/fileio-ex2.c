#include <stdio.h>
#include <ctype.h>
#define FILE_NAME "test.txt"

int main()
{
    FILE *fPntrIn;
    int c;
    
    fPntrIn = fopen(FILE_NAME, "r");
    
    if (fPntrIn == NULL) {
        printf("There was an error opening the file");
        return -1;
    }
    
    FILE *fPntrTemp;
    
    fPntrTemp = fopen("temp.txt", "w");
    
    if (fPntrTemp == NULL) {
        printf("There was an error opening the file");
        return -1;
    }
    
    while((c = fgetc(fPntrIn)) != EOF) {
        fputc(toupper(c), fPntrTemp);
    }
    
    fclose(fPntrIn);
    fPntrIn = NULL;
    fclose (fPntrTemp);
    fPntrTemp = NULL;
    
    rename("temp.txt", "test.txt");
    remove("temp.txt");
    
    fPntrIn = fopen(FILE_NAME, "r");
    
    if (fPntrIn == NULL) {
        printf("There was an error opening the file");
        return -1;
    }
    
    while((c = fgetc(fPntrIn)) != EOF) {
        printf("%c", c);
    }
}
