#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* insertFront(int num, struct Node *head) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = num;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    }   
    
    head->prev->next = newNode;
    newNode->prev = head->prev;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    
    return head;
}

struct Node* buildList(int nums[], struct Node *head, int size) {
    
    
    for (int i = 0; i < size; i++) {
        head = insertFront(nums[i], head);
    }
    
    return head;
}

struct Node* printList(struct Node *head) {
    struct Node *p = head;
    
    printf("%d ", p->data);
    p = p->next;
    
    while (p != head) {
        printf("%d ", p->data);
        p = p->next;
    }
    
    printf("\n");
}

struct Node* printReverse(struct Node *head) {
    struct Node *p = head->prev;
    
    while (p != head) {
        printf("%d ", p->data);
        p = p->prev;
    }
    
    printf("%d", p->data);
    
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    
    int nums[] = {1, 2, 3, 4, 5}; 
    
    int size = sizeof(nums) / sizeof(nums[0]);
    
    printf("nums size: %d\n", size);
    
    head = buildList(nums, head, size);
    
    printList(head);
    printReverse(head);

    return 0;
}
