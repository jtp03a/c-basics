#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseStr(char str[]);
void sortStr(char **strArr, int numStr);

void reverseStr(char str[]) {

  for (int i = 0; i < strlen(str); i++) {
      char reversedChar = str[(strlen(str)-1) - i];
      printf("%c", reversedChar);
  }
  printf("\n");
}

void sortStr(char **strArr, int numStr) {
  for (int i = 0; i < numStr; i++) {
    printf("%s\n", strArr[i]);
  }
}

int main(){
  char buf[100];
  
  printf("Enter a string no longer than 100 characters: ");
  
  scanf("%s", buf);
  
  reverseStr(buf);

  int numStr = 0;

  printf("Enter the number of strings in the array: ");
  scanf("%i", &numStr);

  char strArr[25][100];

  for (int i = 0; i < numStr; i++){
    printf("Enter string %i:\n", i);
    scanf("%s", strArr[i]);
  }
 
  sortStr(strArr, numStr);
    
  return 0;
}

