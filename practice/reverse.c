#include <stdio.h>
#include <stdlib.h>

void reverse(char str[], int size) {
    for (int i = size; i >= 0; i--) {
        printf("%c", str[i]);
    }
}


int main()
{
    char str[] = "Jacob Peterson";
    
    int size = sizeof(str) / sizeof(str[0]);
    
    reverse(str, size);

    return 0;
}
