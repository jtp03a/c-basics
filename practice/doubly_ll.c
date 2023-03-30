/* See README.md for instructions*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Refer to README.md for the problem instructions
typedef struct nameNode
{
    const char *name;
    struct nameNode *next;
    struct nameNode *prev;
}nameNode;


nameNode *buildList(const char **names, int size)
{
    nameNode *head = (nameNode*) malloc(sizeof(nameNode));
    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        nameNode *newNode = (nameNode*) malloc(sizeof(nameNode));
        newNode->name = names[i];
        newNode->next = NULL;
        newNode->prev = NULL;

        // first node in list
        if (head == NULL ) {
            head = newNode;
        //insert new node at head
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    return head;
}

nameNode *removeNode(nameNode *head, const char *findName)
{
    return head;
}

void freeMemory(nameNode *head)
{

}

int main() {

    // main driver
    const char *names[] = { "Joe","Ace","Gene","Paul","Peter","Hank","Timmy","Sarah","Alice","Carol" };
    
    nameNode *head = buildList(names, sizeof(names) / sizeof(*names));
    
    printf("The name in head is : %s\n", head->name);
    
    //Traverse list
    nameNode *current = (nameNode*) malloc(sizeof(nameNode));
    current = head;
    
    //traverse to end
    while (current->next != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
    printf("Data at the tail: %s\n", current->name);
    // traverse in reverse
    // while (current != NULL) {
    //     printf("%s\n", current->name);
    //     current = current->prev;
    // }
    
    
    
    
    return 0;
}

