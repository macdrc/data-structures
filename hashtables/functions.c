#include <stdio.h>
#include <stdlib.h>
#include "header.h"

node* create_node (char new_name, unsigned long long new_phone){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->next = NULL;
    new_node->name = new_name;
    new_node->phone = new_phone;
    return new_node;
}

list* create_list (){
    list* new_list = (list*) malloc(sizeof(list));
    if (new_list == NULL)
        return NULL;
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->count = 0;
    return new_list;
}

list* add_node_tail (list* my_list, node* new_tail){
    if (my_list == NULL || new_tail == NULL)
        return NULL;
    if (my_list->head == NULL){
        my_list->head = new_tail;
        my_list->tail = new_tail;
        my_list->count = 1;
    }
    else{
    my_list->tail->next = new_tail;
    my_list->tail = new_tail;
    ++my_list->count;
    }
    return my_list;
}

// returns an index number from a node using the phone
int hash_function (unsigned long long phone){
    int ix = phone % SIZE;
    return ix;
}

int add_to_hastable (list* hashtable [], node* my_node){
    if(my_node == NULL)
        return -1;

    int ix = hash_function(my_node->phone);
    add_node_tail (hashtable [ix], my_node);
}

node* search (list* hashtable [], unsigned long long phone){
    int ix = hash_function(phone);
    node* current_node = hashtable[ix]->head;
    if (current_node == NULL)
        return NULL;
    while(current_node->next != NULL){
        
        if (current_node->phone == phone)
            return current_node;
        current_node = current_node->next;
        if (current_node == NULL)
            return NULL;
    }
}

void print_hashtable (list* hashtable []){
    for (int i = 0; i < SIZE; i++){
        printf("\nindex %d: ", i);
        
        node* current_node = hashtable[i]->head;

        while (current_node != NULL){
            printf("%llu ", current_node->phone);
            current_node = current_node->next;
        }
    }
}

void free_list(node* head){
            if (head == NULL)
                return;
            free_list(head->next);
            free(head);
        }
        
void free_hashtable (list* hashtable []){
    for (int i = 0; i < SIZE; i++){
        node* head1 = hashtable[i]->head;
        
        free_list(head1);
        // After freeing the linked list, set the hashtable entry to NULL
        free(hashtable[i]);
        hashtable[i] = NULL;
    }
}