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

    
    for (int i = 0; i < size; i++) {
        nameNode *newNode = (nameNode*) malloc(sizeof(nameNode));
        
        newNode->name = names[i];
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
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
    
    
    
    return 0;
}
