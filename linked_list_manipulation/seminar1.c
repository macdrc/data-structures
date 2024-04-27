#include <stdio.h>
#include <stdlib.h>


typedef struct node_{
    char name;
    struct node_ *next;
} node;

typedef struct _linked_list {
    int count;
    node* head;
    node* tail;
}list;

list* create_list()
{
    list* newList = (list*)malloc(sizeof(newList));
    newList->head = NULL;
    newList->tail = NULL;
    newList->count = 0;
    return newList;
}

node* create_node (char name)
{
    node* newNode = (node*)malloc(sizeof(newNode));
    newNode->name = NULL;
    newNode->next = NULL;
    return newNode;
}

int add_node_front (list* my_list, node* my_new_node)
{
    if (my_list == NULL)
    {
        return -1;
    }
    
    my_list->count++;
    my_new_node->next = my_list->head;
    my_list->head = my_new_node;

    if(my_list->tail == NULL)
    {
        my_list->tail == my_new_node;
    }
    return 0;
}

int remove_node_front(list* my_list)
{
    if(my_list == NULL)
    {
        return -1;
    }
    if (my_list->head == NULL)
    {
        return 0;
    }
    node* temp = my_list->head;
    my_list->head = temp->next;
    my_list->count--;
    free(temp);
    return 0;
}

int add_node_back (list* my_list, node* my_new_node)
{
    if (my_list == NULL)
    {
        return -1;
    }
    my_list->count++;
    my_list->tail->next = my_new_node;
    my_list->tail = my_new_node;
    if(my_list->head == NULL)
    {
        my_list->head = my_new_node;
    }
    return 0;
}

int remove_node_back (list* my_list)
{
    if (my_list == NULL)
    {
        return -1;
    }
    node* current_node = my_list->head;

    if (my_list->head == NULL)
    {
        return 0;
    }
    
    if (my_list->head->next == NULL)
    {
        free(my_list->head);
        my_list->head = NULL;
        my_list->tail = NULL;
        my_list->count--;
        return 0;
    }

    while (current_node->next->next != NULL)
    {
        current_node = current_node->next;
    }

    free (current_node->next);
    my_list->tail = current_node;
    my_list->tail->next = NULL;
    my_list->count--;
}


int main (int argc, char **argv)
{
    return 0;
}