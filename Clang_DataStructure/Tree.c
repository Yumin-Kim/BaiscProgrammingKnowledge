#include <stdio.h>

typedef struct _node {
    int val;
    struct _node* left;
    struct _node* right;
} node;

void append_node(node * *head, int val);

void print_tree(node * head);

void create_tree();

void get_root();

void get_leaf_count(node *head);

void get_heght(node *head);

int main() {



    return 0;
}



