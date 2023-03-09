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

void deleteFirst(){
    //create a pointer to the current first node in the list
    struct Node *startList;
    
    //the list is empty
    if (last == NULL) {
        printf("\nThe list is empty\n");
    } else {
        //set the pointer to the current first Node
        startList = last->next;
        //set the last node to point to the current second node
        //which will become the new first node
        last->next = startList->next;
        free(startList);
        startList = NULL;
    }
}

void deleteLast() {
    //need to know the second to last node so that it can become the new last
    //and be directed to the point to the start of the list
    
    //create a pointer to the start of the list
    struct Node *currListPos;
    currListPos = last->next;
    
    if (last == NULL) {
        printf("\nThe list is empty\n");
    } else {
        //advance to the current position to the second to last
        while(currListPos->next != last) {
            currListPos = currListPos->next;
        }
        
        //set the second to last node next to point to the start of the list since it will 
        //become the new last after the current last is deleted
        currListPos->next = last->next;

        free(last);
        
        //set what was the second to last node to now be the last
        last = currListPos;
    }
}

void deleteAtIndex(int index) {
    //if the requsted insert position is less than 0 or greater than the 
    //list length
    if(index<0 || index > getListLength()) {
        printf("\nInvalid delete position requested\n");
        return;
    }
    
    //if deleting the first position 
    if (index == 0) {
        deleteFirst();
    //if the requested delete position is at the end
    } else if (index == getListLength()) {
        deleteLast();
    } else {
        //start at the front of the list
        struct Node *currListPos, *deletePos;
        currListPos = last->next;
        
        //advance the list to node before the requested delete position
        for (int i = 0; i<index-1; i++) {
            currListPos = currListPos->next;
        }

        //set the delete position, since we are at the node before the requested
        //delete position the delete node is equal to the current position's next
        deletePos = currListPos->next;
        //reassign the next of the node before the delete position to the node
        //after the delete position
        currListPos->next = deletePos->next;
        
        free(deletePos);
        deletePos = NULL;
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
    
  insertAtIndex(6000, 1);
  
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
  
  deleteFirst();
  deleteFirst();
  
  viewList();
  printf("\n");
  
  deleteLast();
  
  viewList();
  printf("\n");
  
  deleteAtIndex(1);
  deleteAtIndex(6);
  deleteAtIndex(0);
  
  viewList();
  printf("\n");
}
