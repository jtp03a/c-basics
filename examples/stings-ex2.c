#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseStr(char str[]);

void reverseStr(char str[]) {
  strlen(str);
}

int main(){
  char buf[100];
  
  printf("Enter a string no longer than 100 characters");
  
  scanf("%s", buf);
  
  reverseString(buf);

  printf("%s\n", buf);
    
  return 0;
}

