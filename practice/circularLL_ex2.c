#include <stdlib.h>
#include <stdio.h>

//Structure of a linked list node
struct Node {
  int data;
  struct Node *next;
};

//pointer to last node in the list
struct Node *last = NULL;

void insertAtFront(int data){
  //initialize a new node
  struct Node *newNode;
  newNode = (struct Node*)malloc(sizeof(struct Node));
  
  //if the new node is the only node in the list
  if (last == NULL) {
    newNode->data = data;
    //the newNode points back to itself
    newNode->next = newNode;
    //last points to the newNode
    last = newNode;
  } else {
    newNode->data = data;
    //the newNode->next points to whatever the previous first node was
    //last->next was pointing to the previous first node
    newNode->next = last->next;
      
    //point the last to the new first node
    last->next = newNode;
  }
}

void insertAtEnd(int data){
    //initialize a new node
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    //if the new node is the only node in the list
    if (last == NULL) {
        newNode->data = data;
        //if the new node is the only one in the list is should
        //point back to itself
        newNode->next = newNode;
        //last is also the new node if its the only one in the list
        last = newNode;
    } else {
        newNode->data = data;
        //the new node which is now the new last node will point to last->next
        //which is the first node
        newNode->next = last->next;
        //since we are inserting at the end whatever was the old last node, its 
        //new next should be the new node
        last->next = newNode;
        //new last is now the new node
        last = newNode;
    }
}

void insertAtIndex(int data, int index) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    //if the requsted insert position is less than 0 or greater than the 
    //list length
    if(index<0 || index > getListLength()) {
        printf("\nInvalid insert position requested\n");
        return;
    }
    
    //if inserting into the first position 
    if (index == 0) {
        insertAtFront(data);
    //if the requested insert position is at the end
    } else if (index == getListLength()) {
        insertAtEnd(data);
    } else {
        //start at the front of the list
        struct Node *currListPos;
        currListPos = last->next;
        
        //advance the list to node before the requested insert position
        for (int i = 0; i<index-1; i++) {
            currListPos = currListPos->next;
        }
        newNode->data = data;
        //point the new node next to the whatever the previous node at that position
        //was pointing to
        newNode->next = currListPos->next;
        //point the previous node next to the new new node
        currListPos->next = newNode;
    }
}

void viewList() {
  //if the list is empty
  if (last == NULL) {
    printf("\nList is empty\n");
  } else {
    //print the list
    //make a pointer to the start of the list
    struct Node *currListPos;
    //last->next points to the start of the list
    currListPos = last->next;
    
    //use a do while loop to make sure the current list position gets
    //advanced atleast one time and then stops when it gets back to the
    //start of the list again
    do {
      printf("\nData = %d", currListPos->data);
      currListPos = currListPos->next;
    } while (currListPos != last->next);
  }
}

int getListLength() {
  //if the list is empty
  if (last == NULL) {
    printf("\nList is empty\n");
    return 0;
  } else {
    int count = 0;
    //make a pointer to the start of the list
    struct Node *currListPos;
    //last->next points to the start of the list
    currListPos = last->next;
    
    //use a do while loop to make sure the current list position gets
    //advanced atleast one time and then stops when it gets back to the
    //start of the list again
    do {
      currListPos = currListPos->next;
      count++;
    } while (currListPos != last->next);
    return count;
  }
}

int main () {
  insertAtFront(10);
  insertAtFront(20);
  insertAtFront(30);
  
  viewList();  
  printf("\n");
  
  insertAtEnd(1);
  insertAtEnd(2);
  insertAtEnd(3);
  
  viewList();
  printf("\n");
  
  insertAtIndex(100, 1);
  insertAtIndex(200, 0);
  insertAtIndex(300, 8);
  insertAtIndex(400, -5);
  insertAtIndex(500, 8);
  
  viewList();
  printf("\n");
  
  printf("List length: %d\n", getListLength());
}
