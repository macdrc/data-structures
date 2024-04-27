#include <stdlib.h>

typedef struct _node{
    char name;
    struct node* next;
} node;

typedef struct _list{
    int count;
    node* head;  // first element in the list
} list;


int main (int argc, char *argv[]) {

    list* myList = (list*)malloc(sizeof(list)); // the reurn is typecast
    node* nodeA = (node*)malloc(sizeof(node));
    node* nodeB = (node*)malloc(sizeof(node));
    node* nodeC = (node*)malloc(sizeof(node));

    nodeA->name = 'A';
    nodeA->next = nodeB;

    nodeB->name = 'B';
    nodeB->next = nodeC;

    nodeB->name = 'B';
    nodeB->next = nodeC;

    myList->count = 3;
    myList->head = nodeA;

    return 0;

}