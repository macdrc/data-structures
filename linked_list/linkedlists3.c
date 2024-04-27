
#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char name;
    struct _node *next;
}node;

typedef struct _list{
    node *head;
    node *tail;
    int count;
}list;

node* getNewNode (char name)
{
    node* newNode = NULL;
    newNode = malloc(sizeof(newNode));
    printf("node %c created \nlocation: %p \n", name, newNode);
    if (newNode != NULL)
    {
        newNode->name = name;
        newNode->next = NULL;
    }
    else
    {
        printf("Memory allocation error!");
    }
    return newNode;
}

list CreateList (char name, int count)
{
    int i = count;
    char n = 'a';
    node* first = NULL;
    node* last = NULL;
    node* added = NULL;
    list* NewList = NULL;

    NewList = malloc(sizeof(NewList));
    if (NewList != NULL && i >= 3)
    {
        first = getNewNode(n++);
        added = getNewNode(n++);
        first->next = added;
        NewList->head = first;
        i--;
        while (i>1)
        {
            added->next = getNewNode(n++);
            added = added->next;
            i--;
        }
        last = getNewNode(n++);
        last->next = NULL;
        NewList->tail = last;
    }
    else
    {
        printf("Allocation error or count entered is less than 3");
    }
}

node printList (node* head){

}


int main (int argc, char **argv)
{
    node* temp;
    int count;
    char name;
    printf("Enter the name of a new list (char) \n");
    scanf("%s", &name);

    printf("Enter the amount of nodes (3 or more) \n");
    scanf("%d", &count);

    printf("Creating linkedlist named %c with %d nodes ...\n", name, count);
    
    CreateList(name, count);

    printf("Press any key and 'ENTER' to cleanup\n");
    scanf("%d");

    printf("Cleaning up..\n");

    return 0;
}