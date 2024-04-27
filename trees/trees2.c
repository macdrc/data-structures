#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
    int data;
    struct _node *left;
    struct _node *right;
} node;

typedef struct _tree {
    int count;
    node *root;
} tree;


tree* create_tree (){
    tree *new_tree = (tree*)malloc(sizeof(tree));
    new_tree->count = 0;
    new_tree->root = NULL;
    return new_tree;
}

node* create_node (int value){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int add_node (tree *my_tree, node *value){
    if (my_tree == NULL)
        return -1;
    if (my_tree->root == NULL){
        my_tree->root = value;
        my_tree->count = 1;
        return 0;
    }

    node *current_node = my_tree->root;
    ++(my_tree->count);

    while(1)
    {
        if(value->data > current_node->data){   // if 16 > 10
            if (current_node->left == NULL){
                current_node->left = value;
                return 0;
            }
            current_node = current_node->left;
        }
        else {
            if(current_node->right == NULL){
                current_node->right = value;
                return 0;
            }
            current_node = current_node->right;
        }
    }
}


int print_ascending(node* root) {
    if(root == NULL) 
        return -1;
    print_ascending(root->right);

    printf(" %d ", root->data);
    print_ascending (root->left);
    
    return 0;
}

int main (int argc, char **argv)
{   
    tree* new_tree = create_tree();
    add_node(new_tree, create_node(10));
    add_node(new_tree, create_node(8));
    add_node(new_tree, create_node(20));
    add_node(new_tree, create_node(5));
    add_node(new_tree, create_node(9));
    add_node(new_tree, create_node(16));
    add_node(new_tree, create_node(35));
    add_node(new_tree, create_node(12));
    add_node(new_tree, create_node(19));
    add_node(new_tree, create_node(45));
    add_node(new_tree, create_node(55));
    add_node(new_tree, create_node(11));

    print_ascending(new_tree->root);

    return 0;
}
