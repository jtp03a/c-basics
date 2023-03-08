/*****************************************
Notes - Linked Lists
  Problems with arrays - have to specify size and cant increase or decrease (without dynamic memory allocation)
******************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
}*Head;

void createLL(int arr[], int n) {
  int i;
  struct Node *t, *last;
  
  Head = (struct Node*)malloc(sizeof(struct Node));
  Head->data=arr[0];
  Head->next=Head;
  last = Head;
  
  for(i=1;i<n;i++){
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=arr[i];
    t->next=last->next;
    last->next=t;
    last=t;
  }
}

void displayLL(struct Node *h){
  do {
    printf("%d ", h->data);
    h = h->next;
  } while (h!=Head);
  printf("\n");
}

void recursiveDisplay(struct Node *h) {
    static int flag = 0;
    if(h != Head || flag==0){
        flag=1;
        printf("%d ", h->data);
        recursiveDisplay(h->next);
    }
    flag = 0;
}

void insertLL(struct Node *h, int index, int x){
    struct Node *t;
    int i;
    
    if(index<0 || index > lengthLL(h)) {
        return;
    }
    
    if (index == 0) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        if (Head == NULL) {
            Head =t;
            Head->next = Head;
        } else {
            while (h->next != Head)h = h->next;
    
            h->next = t;
            t->next = Head;
            Head = t;
        }
    } else {
        for(i=0;i<index - 1; i++)h=h->next;
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        t->next=h->next;
        h->next=t;
    }
}

int lengthLL(struct Node *h) {
    int len=0;
    
    do {
        len++;
        h=h->next;
    } while (h != Head);
    return len;
}

int main(){
  int arr[] = {2, 3, 4, 5, 6};
  
  int size = sizeof(arr) / sizeof(arr[0]);
  
  createLL(arr, size);
//   displayLL(Head);
  recursiveDisplay(Head);
  printf("\n");
  
  insertLL(Head, 5, 10);
  displayLL(Head);
}
