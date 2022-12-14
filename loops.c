/**********************************************
For Loop:
  for (starting condition; continuation condition; action per iteration) {
    loop statements;
   }
   
  Variables will be local to the loop and will not exist once the loop ends
  Continuation condition is tested at the beginning of the loop i.e loop statment
   will not be executed at all if the continuation condition starts out false
  Action per iteration is exectuted at the end of each loop iteration
  
**********************************************/

#include <stdio.h>

int main() {

  for (int i = 1, j = 2; i <= 5; ++i, j = j + 2) {
    printf(" %5d", i * j);  
  }
  
  return 0;
}
