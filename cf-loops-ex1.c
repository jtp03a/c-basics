#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
//   random numbers
//   create time variable
  time_t t;
//   initialize random number generator
  srand((unsigned) time(&t));
//   generate the random number and store in int
  int randomNumber = rand() % 21;
//   initialize and declare game variables
  int userGuess = 0;
  int attemptsRemaining = 5;
//   input display
  printf("\nGuess the random number from 1-20: ");
//   main game loop
  while (userGuess != randomNumber) {
    scanf("%d", &userGuess);
    // check for valid input 
    if (userGuess < 1 || userGuess > 20) {
        printf("\nInvalid Number, enter a number between 1-20: ");
        continue;
    }
    // decrement the attempt counter
    attemptsRemaining--;
    // check for a correct guess
    if (userGuess == randomNumber) {
      printf("You got it");
    } else {
      // end game if attempts run out
      if (attemptsRemaining == 0) {
          printf("You ran out of tries");
          break;
      }
      // give user hints   
      if (userGuess > randomNumber) {
          printf("\nYour guess was too high");
      } else {
          printf("\nYour guess was too low");
      }
      // request input again if incorrect guess
      printf("\nAttempts Remaining: %d, Try again: ", attemptsRemaining);
    }

  }

  return 0;
}
