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
  char tempStr[100];
  int price;
  int quantity;
  

  printf("Enter the product name: ");
  scanf("%s", tempStr);
  strcpy(i->itemName, tempStr);
  
  printf("Enter the produce price: ");
  scanf("%f", &price);
  printf("Enter the product quantity: ");
  scanf("%i", &quantity);
  
  i->price = price;
  i->quantity = quantity;
  
}

void printItem(struct item * i) {
  printf("%s, %.2f, %i", i->itemName, i->price, i->quantity);
}

int main() {
  
  struct item ball, *pBall;
  
  pBall = &ball;
  
  pBall->itemName = (char *)malloc(30 * sizeof(char));
  
  if(pBall) {
      exit(-1);
  }
  
  readItem(pBall);
  printItem(pBall);

  return 0;
}
