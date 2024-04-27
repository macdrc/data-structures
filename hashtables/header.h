#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

typedef struct node_ {
    char name;
    unsigned long long phone;
    struct node_ *next;
} node;

typedef struct list_ {
    node *head;
    node *tail;
    int count;
} list;

node* create_node (char new_name, unsigned long long new_phone);
list* create_list();

list* add_node_tail (list* my_list, node* new_tail);

int hash_function (unsigned long long phone);

int add_to_hastable (list* hashtable [], node* my_node);

node* search (list* hashtable [], unsigned long long phone);

void print_hashtable (list* hashtable []);
void free_list(node* head);
void free_hashtable (list* hashtable []);

