#include <stdio.h>

int main()
{
    FILE *fPntr;
    int c;
    int lineCounter;
    
    fPntr = fopen("test.txt", "r");
    
    if(fPntr != NULL) {
        while((c=fgetc(fPntr)) != EOF) {
            printf("%c", c);
            if (c == '\n') {
                lineCounter++;
            }
        }
        printf("The total number lines detected is: %i", lineCounter);
    }
    
    fclose(fPntr);
    fPntr = NULL;

    return 0;
}
