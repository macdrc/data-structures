#include <stdlib.h> // to be able to use malloc functions
#include <stdio.h>

typedef struct _node
{
    char name; // not required for a linked list
    struct _node * next; // points to the next node in the list
} node;

typedef struct _linked_list {
    int count;
    node * head;
    node * tail;
} list;

list * create_list() {
    list* result = (list *) malloc(sizeof(list));
    result->head = NULL;
    result->tail = NULL;
    result->count = 0;
    return result;
}

node * create_node(char name) {
    node * result = (node *)malloc(sizeof(node));
    result->next = NULL;
    result->name = name;
    return result;
}

int add_node_front(list* my_list, node* my_new_node) {
    if(my_list == NULL)
        return -1;
    ++my_list->count;
    my_new_node->next = my_list->head;
    my_list->head = my_new_node;
    if(my_list->tail == NULL)
        my_list->tail = my_new_node;

    return 0;
}

int erase_front(list* my_list) {
    if(my_list == NULL)
        return -1;
    if(my_list->head == NULL)
        return 0;

    node * item = my_list->head;
    my_list->head = item->next;
    if(my_list->head == NULL)
        my_list->tail = NULL;

    --my_list->count;

    return 0;
}

int print_list(list* my_list) {
    if(my_list == NULL)
        return -1;

    node* item = my_list->head;

    printf(" \n");
    while (item != NULL)
    {
        printf("%c", item->name);
        item = item->next;
    }    
    printf(" \n");

    return 0;
}

int main(int argc, char** argv) {
    list* my_list = create_list();

    add_node_front(my_list, create_node('B'));
    add_node_front(my_list, create_node('A'));
    add_node_front(my_list, create_node('C'));

    print_list(my_list);

    while (my_list->count > 0)
    {
        erase_front(my_list);
    }
    
    return 0;
}