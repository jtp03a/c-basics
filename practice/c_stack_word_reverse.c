#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  char input[256];		// Will store string
  printf ("Enter a string: ");	// Prompts user
  fgets (input, sizeof (input), stdin);	// Stores user string

  char *buffer = (char *) malloc ((strlen(input)) * sizeof (char));

  buffer = strncpy (buffer, input, strlen(input) -1);

  printf ("buffer: %s\n", buffer);

  //tokenize, strtok()
  const char token[2] = " ";
  char *tokenized = NULL;

  //find first token
  tokenized = strtok (buffer, token);
  int stack_size = 0;

  //find the remaining tokens
  while (tokenized != NULL)
    {
      stack_size++;

      tokenized = strtok (NULL, token);
    }

  buffer = strncpy (buffer, input, strlen(input) -1);

  char *stack[stack_size];
  int top = -1;

  tokenized = NULL;

  //find first token
  tokenized = strtok (buffer, token);

  //find the remaining tokens
  int i = 0;
  
  while (tokenized != NULL)
    {
      top+=1;
      stack[top] = tokenized;
      tokenized = strtok (NULL, token);
    }

  //push(stack, top, str);

  for (; top > -1; top--)
    {
      printf ("%s\n", stack[top]);
    }

  // free(buffer);
  // free(stack);

  return 0;
}
