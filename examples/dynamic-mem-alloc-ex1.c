#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
  int allocSize = 0;
  char * text = NULL;
  
  printf("How long is the string: \n");
  
  scanf("%d", &allocSize);
  
  text = (char*)malloc(allocSize * sizeof(char));
  
  if (text) {
      printf("Enter some text: \n");
      scanf(" ");
      gets(text);
      
      printf("Inputted text is %s\n", text);
  }

  free(text);
  text = NULL;
  
  return 0;
}
