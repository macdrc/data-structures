#include <stdlib.h>
#include <stdio.h>

//=========================STRUCTURES===============================
typedef struct node_ {                                        // 2
    int pid;
    char name;
    struct node_ *left;
    struct node_ *right;
} node;

typedef struct tree_ {                                        // 3
    node *root;
    int count;
} tree;
//=========================PROTOTYPES==============================
node* create_node (int pid, char my_name);                    // 4
tree* create_tree ();                                         // 5
int add_to_tree_pid (tree* my_tree, node* my_node);           // 6

int print_ascending (node *root);                             // 7
int print_decending (node *root);                             // 8

int remove_node_with_pid (node *root, int my_pid, tree *my_tree);        // 9
node* remove_node_and_return_it (node *root, int my_pid, tree *my_tree); // 10

int check_pid_in_tree (node *root, int my_pid);               // 11

int add_to_tree_alphabetical(tree* my_tree, node* my_node);   // 12

int find_size_of_tree (node *root);                           // 13
node* make_copy_of_tree (node *root, tree *new_tree);         // 14

int count_nodes_with_char (node *root, char my_name);         // 15
int sum_of_all_pid (node *root);                              // 16
int print_all_even_details (node *root);                      // 17

int get_max_total_branch_value (node *root);                  // 18
int get_longest_branch_size (node *root);                     // 19

//========================MAIN FUNCTION==============================
//===================================================================
int main (int argc, char** argv){

    tree* my_tree = create_tree();

    //--------------( 6 )--------------//
    // Some contain the same name 'A'
    add_to_tree_pid (my_tree, create_node(20, 'A'));
    add_to_tree_pid (my_tree, create_node(16, 'B'));
    add_to_tree_pid (my_tree, create_node(30, 'C'));
    add_to_tree_pid (my_tree, create_node(12, 'D'));
    add_to_tree_pid (my_tree, create_node(18, 'E'));
    add_to_tree_pid (my_tree, create_node(26, 'A'));
    add_to_tree_pid (my_tree, create_node(40, 'G'));
    add_to_tree_pid (my_tree, create_node(10, 'H'));
    add_to_tree_pid (my_tree, create_node(14, 'I'));
    add_to_tree_pid (my_tree, create_node(17, 'J'));
    add_to_tree_pid (my_tree, create_node(19, 'K'));
    add_to_tree_pid (my_tree, create_node(21, 'L'));
    add_to_tree_pid (my_tree, create_node(35, 'M'));
    add_to_tree_pid (my_tree, create_node(45, 'N'));
    add_to_tree_pid (my_tree, create_node(65, 'O'));

    //--------------( 12 )-------------//
    // add_to_tree_alphabetical (my_tree, create_node(20, 'A'));
    // add_to_tree_alphabetical (my_tree, create_node(16, 'B'));
    // add_to_tree_alphabetical (my_tree, create_node(30, 'C'));
    // add_to_tree_alphabetical (my_tree, create_node(12, 'D'));
    // add_to_tree_alphabetical (my_tree, create_node(18, 'E'));
    // add_to_tree_alphabetical (my_tree, create_node(26, 'F'));
    // add_to_tree_alphabetical (my_tree, create_node(40, 'G'));
    // add_to_tree_alphabetical (my_tree, create_node(10, 'H'));
    // add_to_tree_alphabetical (my_tree, create_node(14, 'I'));
    // add_to_tree_alphabetical (my_tree, create_node(17, 'J'));
    // add_to_tree_alphabetical (my_tree, create_node(19, 'K'));
    // add_to_tree_alphabetical (my_tree, create_node(21, 'L'));
    // add_to_tree_alphabetical (my_tree, create_node(35, 'M'));
    // add_to_tree_alphabetical (my_tree, create_node(45, 'N'));
    // add_to_tree_alphabetical (my_tree, create_node(65, 'O'));


    //--------------( 7 )----------------------------//
    printf("\n-------PRINT ASCENDING----------------\n");
    print_ascending (my_tree->root);
    printf("\n");

    //--------------( 8 )----------------------------//
    printf("\n-------PRINT DESCENDING---------------\n");
    print_decending (my_tree->root);
    printf("\n");

    //--------------( 9 )----------------------------//
    printf("\n-------REMOVE AND FREE NODE-----------\n");
    remove_node_with_pid (my_tree->root, 40, my_tree);
    print_ascending (my_tree->root);
    printf("\n");

    //--------------( 10 )---------------------------//
    printf("\n-------REMOVE AND RETURN NODE---------\n");
    node *removed_node = remove_node_and_return_it (my_tree->root, 30, my_tree);
    printf ("Returned node = %d%c\n", removed_node->pid, removed_node->name);
    print_ascending (my_tree->root);
    printf("\n");

    //--------------( 11 )---------------------------//
    printf("\n-------CHECK PID IN TREE--------------\n");
    check_pid_in_tree (my_tree->root, 30);
    
    //--------------( 13 )---------------------------//
    printf("\n-------FIND SIZE OF TREE--------------\n");
    printf("Count is %d, Manual count is %d\n", my_tree->count, find_size_of_tree (my_tree->root));

    //--------------( 14 )---------------------------//
    printf("\n-------COPY THE TREE------------------\n");
    tree *tree2 = create_tree();
    tree2->root = make_copy_of_tree (my_tree->root, tree2);
    printf("Original tree:\n");
    print_ascending (my_tree->root);
    printf("\nCopied tree:\n");
    print_ascending (tree2->root);
    printf("\n");

    //--------------( 15 )---------------------------// Cannot be used with alphabetical adding to tree
    printf("\n-------COUNT NODES WITH CHAR----------\n");
    printf ("Nodes with A in my_tree: %d\n", count_nodes_with_char (my_tree->root, 'A'));

    //--------------( 16 )---------------------------//
    printf("\n-------SUM OF ALL PID'S---------------\n");
    printf ("Sum of all pid in my_tree: %d\n", sum_of_all_pid (my_tree->root));
    
    //--------------( 17 )---------------------------//
    printf("\n-------PRINT ALL EVEN DETAILS---------\n");
    print_all_even_details (tree2->root);
    printf("\n");
    
    //--------------( 18 )---------------------------//
    printf("\n-------GET MAX BRANCH VALUE-----------\n");
    printf ("Max total branch value of my_tree is: %d\n", get_max_total_branch_value (my_tree->root));
    
    //--------------( 19 )---------------------------//
    printf("\n-------GET LONGEST BRANCH SIZE--------\n");
    printf ("Longest branch size of my_tree is: %d\n", get_longest_branch_size (my_tree->root));
    
    printf("\n\n");
    return 0;
}

//======================FUNCTION DECLARATIONS=======================
//=============================================================( 4 )
node* create_node (int pid, char my_name){
    node* new_node = malloc(sizeof(node));
    new_node->pid = pid;
    new_node->name = my_name;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

//=============================================================( 5 )
tree* create_tree (){
    tree* new_tree = malloc(sizeof(tree));
    new_tree->root = NULL;
    new_tree->count = 0;
    return new_tree;
}

//=============================================================( 6 )
int add_to_tree_pid (tree* my_tree, node* my_node){
    if (my_tree == NULL || my_node == NULL)
        return -1;
    if (my_tree->root == NULL){
        my_tree->root = my_node;
        my_tree->count = 1;
        return 0;
    }
    ++(my_tree->count);
    node* current_node = my_tree->root;

    while (1){
        if (my_node->pid < current_node->pid){
            if (current_node->left == NULL){
                current_node->left = my_node;
                return 0;
            }
            current_node = current_node->left;
        }
        else {
            if (my_node->pid > current_node->pid){
                if (current_node->right == NULL){
                    current_node->right = my_node;
                    return 0;
                }
            }
            current_node = current_node->right;
        }
    }  
}

//=============================================================( 7 )
int print_ascending (node *root){
    if (root == NULL)
        return -1;
    print_ascending (root->left);
    printf ("%d%c ", root->pid, root->name);
    print_ascending (root->right);
    return 0;
}

//=============================================================( 8 )
int print_decending (node *root){
    if (root == NULL)
        return -1;
    print_decending (root->right);
    printf ("%d%c ", root->pid, root->name);
    print_decending (root->left);
    return 0;
}

//=============================================================( 9 )
int remove_node_with_pid (node* root, int my_pid, tree *my_tree){
    if (root == NULL)
        return -1;
    
    node* item = root;
    node** pre = &root;
    while(item->pid != my_pid) {
        if(item->pid < my_pid) {
            pre = &item->right;
            item = item->right;
        }
        else {
            pre = &item->left;
            item = item->left;
        }

        if(item == NULL)
            return 0;
    }

    if((item->left == NULL) && (item->right == NULL)) {
        *pre = NULL;
        free(item);
    }
    if((item->left != NULL) && (item->right == NULL)) {
        *pre = item->left;
        free(item);
        return 0;
    }
    if((item->left == NULL) && (item->right != NULL)) {
        *pre = item->right;
        free(item);
        return 0;
    }

    node* max_node = item->right;
    node** pre_max = &item->right;
    while (max_node->left != NULL)
    {
        pre_max = &max_node->left;
        max_node = max_node->left;
    }
    
    *pre_max = max_node->right;
    *pre = max_node;
    max_node->left = item->left;
    max_node->right = item->right;

    printf ("Node %d%c removed\n", item->pid, item->name);
    my_tree->count--;
    free(item);
    return 0;
}

//=============================================================( 10 )
node* remove_node_and_return_it (node *root, int my_pid, tree *my_tree){
    if (root == NULL)
        return NULL;
    
    node* item = root;
    node** pre = &root;
    while(item->pid != my_pid) {
        if(item->pid < my_pid) {
            pre = &item->right;
            item = item->right;
        }
        else {
            pre = &item->left;
            item = item->left;
        }

        if(item == NULL)
            return root;
    }

    if((item->left == NULL) && (item->right == NULL)) {
        *pre = NULL;
        free(item);
    }
    if((item->left != NULL) && (item->right == NULL)) {
        *pre = item->left;
        return  item;
    }
    if((item->left == NULL) && (item->right != NULL)) {
        *pre = item->right;
        return  item;
    }

    node* max_node = item->right;
    node** pre_max = &item->right;
    while (max_node->left != NULL)
    {
        pre_max = &max_node->left;
        max_node = max_node->left;
    }
    
    *pre_max = max_node->right;
    *pre = max_node;
    max_node->left = item->left;
    max_node->right = item->right;
    my_tree->count--;
    printf ("Node %d%c removed and returned\n", item->pid, item->name);
    return item;
}

//=============================================================( 11 )
int check_pid_in_tree (node *root, int my_pid){
    if (root == NULL){
        printf("pid %d NOT IN THE TREE!!!\n", my_pid);
        return 0;
    }
    if (root->pid == my_pid){
        printf("%d found in node %c\n", my_pid, root->name);
        return 1;
    }
    if (my_pid < root->pid)
        return check_pid_in_tree (root->left, my_pid);
    if (my_pid > root->pid)
        return check_pid_in_tree (root->right, my_pid);
}

//=============================================================( 12 )
int add_to_tree_alphabetical(tree* my_tree, node* my_node){
    if (my_tree == NULL || my_node == NULL)
        return -1;
    if (my_tree->root == NULL){
        my_tree->root = my_node;
        my_tree->count = 1;
        return 0;
    }
    ++(my_tree->count);
    node* current_node = my_tree->root;

    while (1){
        if (my_node->name < current_node->name){
            if (current_node->left == NULL){
                current_node->left = my_node;
                return 0;
            }
            current_node = current_node->left;
        }
        else {
            if (my_node->name > current_node->name){
                if (current_node->right == NULL){
                    current_node->right = my_node;
                    return 0;
                }
            }
            current_node = current_node->right;
        }
    } 
}

//=============================================================( 13 )
int find_size_of_tree (node *root){
    if (root == NULL)
        return 0;
    else {
    int left_size = find_size_of_tree (root->left);
    int right_side = find_size_of_tree (root->right);
    return 1 + left_size + right_side;
    }
}

//=============================================================( 14 )
node* make_copy_of_tree (node *root, tree *new_tree){
    if (root == NULL)
        return NULL;
    else {
        node* new_node = create_node(root->pid, root->name);
        new_tree->count++;
        new_node->left = make_copy_of_tree (root->left, new_tree);
        new_node->right = make_copy_of_tree (root->right, new_tree);
        return new_node;
    }
}

//=============================================================( 15 )
int count_nodes_with_char (node *root, char my_name){
    if (root == NULL)
        return 0;

    int count = 0;
    
    if (root->name == my_name) {
        count++;
    }
    return count 
    + count_nodes_with_char (root->left, my_name)
    + count_nodes_with_char (root->right, my_name);
}

//=============================================================( 16 )
int sum_of_all_pid (node *root){
    if (root == NULL)
        return 0;
    
    else {
        return root->pid
        + sum_of_all_pid (root->left)
        + sum_of_all_pid (root->right);
    }
}

//=============================================================( 17 )
int print_all_even_details (node *root){
    if (root == NULL)
        return -1;

    // same as print_ascending, but checking if even
    if (root->pid % 2 == 0){
        print_all_even_details (root->left);
        printf ("%d%c ", root->pid, root->name);
        print_all_even_details (root->right);
        return 0;
    }
}

//=============================================================( 18 )
int get_max_total_branch_value (node *root){
    if (root == NULL)
        return 0;
    int max_left = get_max_total_branch_value (root->left);
    int max_right = get_max_total_branch_value (root->right);

    int largest;

    if (max_left > max_right)
        largest = max_left;
    else
        largest = max_right;

    int final_sum = largest + root->pid; // where the actual summing is happening

    return final_sum;
}

//=============================================================( 19 )
int get_longest_branch_size (node *root){
    
    // same as branch size, except adding up depths
    if (root == NULL)
        return 0;
    int longest_left = get_longest_branch_size (root->left);
    int longest_right = get_longest_branch_size (root->right);

    int longest;

    if (longest_left > longest_right)
        longest = longest_left;
    else
        longest = longest_right;

    int final_sum = 1 + longest; // where the actual summing is happening

    return final_sum;
}