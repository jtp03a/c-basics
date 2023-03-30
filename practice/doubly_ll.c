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
    nameNode *head = NULL;
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
    nameNode *current = (nameNode*) malloc(sizeof(nameNode));
    current = head;
 
    while (current->next != NULL) {
        if (strcmp(findName, current->name) == 0) {
            printf("Found Match");
            if (current->prev == NULL) {
                head = current->next;
                current->next->prev == NULL;
                free(current);
                return head;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
                return head;
            }
         }
        current = current->next;
    }
    
    return head;
}

void freeMemory(nameNode *head)
{

}

void printList(nameNode *head) {
    nameNode *current = (nameNode*) malloc(sizeof(nameNode));
    current = head;
    printf("[ ");
    //traverse to end
    while (current->next != NULL) {
        printf("%s, ", current->name);
        current = current->next;
    }
    printf("%s ]\n", current->name);
    
    free(current);
}

int main() {

    // main driver
    const char *names[] = { "Joe","Ace","Gene","Paul","Peter","Hank","Timmy","Sarah","Alice","Carol" };
    
    nameNode *head = buildList(names, sizeof(names) / sizeof(*names));
    
    printf("The name in head is : %s\n", head->name);
    
    printList(head);
    head = removeNode(head, "Peter");
    printList(head);
    
    return 0;
}
