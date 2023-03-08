#include <stdio.h>
#include <math.h>

// Refer to README.md for the problem instructions

const double itemPrices[] = {3.50, 2.25, 1.99, 4.15};

int buyGroceries(int stuff[], int size)
{
    struct groceryBasketItem {
        int itemNumber;
        int quantity;
        double itemCost;
    };
    
    struct groceryBasketItem groceryBasket[size / 2];
    
    for (int i = 0; i < size; i+=2) {
        //item numbers
        groceryBasket[i/2].itemNumber = stuff[i];
        groceryBasket[i/2].quantity = stuff[i+1];
        groceryBasket[i/2].itemCost = itemPrices[stuff[i] - 1];
    }
    
   
    double total = 0;
    
    for (int i = 0; i < size / 2; i++) {
        printf("Item Number: %d, Quantity: %d, Item Cost: %f\n", groceryBasket[i].itemNumber, groceryBasket[i].quantity, groceryBasket[i].itemCost);
        total += (groceryBasket[i].quantity * groceryBasket[i].itemCost);
    }
    
    total = round(total);

    return total;
}

int main() {
    
    int cart[] = {1, 5, 2, 3, 4, 4};
    
    int size = sizeof(cart) / sizeof(cart[0]);
    
    int result = buyGroceries(cart, size);
    
    printf("The total cost is: %d: \n", result);
    
    return 0;
}
