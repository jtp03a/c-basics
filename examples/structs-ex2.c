#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
  char *itemName;
  int quantity;
  float price;
  float amount; //stores quantity times price
};

void readItem(struct item * i);
void printItem(struct item * i);

void readItem(struct item * i) {
  printf("Enter the product name: ");
  scanf("%s", i->itemName);
  printf("Enter the produce price: ");
  scanf("%f", &i->price);
  printf("Enter the product quantity: ");
  scanf("%i", &i->quantity);
  
  i->amount = (float)i->quantity * i->price;
}

void printItem(struct item * i) {
  printf("%s, %.2f, %i", i->itemName, i->price, i->quantity);
}

int main() {
  
  struct item ball, *pBall;
  
  pBall = &ball;
  
  pBall->itemName = (char *)malloc(30 * sizeof(char));
  
  if(pBall == NULL) {
      exit(-1);
  }
  
  readItem(pBall);
  printItem(pBall);
  
  free(pBall->itemName);

  return 0;
}
