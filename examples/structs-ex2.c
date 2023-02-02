#include <stdio.h>

struct item {
  char *itemName;
  int quantity;
  float price;
  float amount; //stores quandity times price
};

void readItem(struct * item);
void printItem(struct * item);

void readItem(struct * item) {
  char productName[100];
  int price;
  
  printf("Enter the product name: ");
  scanf("%s", productName);
  printf("Enter the produce price: ");
  scanf("%f", &price);
  printf("Enter the product quantity: ");
  scanf("%i", &quantity);
  
  item->itemName = prodcutName;
  item->price = price;
  item->quantity = quantity;
  
}

void printItem(struct * item) {
  printf("%s, %d, %.2f", item->itemName, item->price, item->quantity);
}

int main() {
  
  struct item ball, *pBall;
  
  readItem(pBall);
  printItem(pBall);

  return 0;
}
