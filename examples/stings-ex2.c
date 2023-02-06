#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseStr(char str[]);

void reverseStr(char str[]) {
  char reversedStr[strlen(str)];
  
  for (int i = 0; i < strlen(str); i++) {
      reversedStr[i - strlen(str)] = str[i];
  }
  
  printf("%s\n", reversedStr);
}

int main(){
  char buf[100];
  
  printf("Enter a string no longer than 100 characters");
  
  scanf("%s", buf);
  
  reverseStr(buf);

  printf("%s\n", buf);
    
  return 0;
}

