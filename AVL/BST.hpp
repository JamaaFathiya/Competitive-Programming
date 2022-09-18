#ifndef BST_HPP
#define BST_HPP

#include <iostream>

typedef struct bst_node{
    int data;
    bst_node* left;
    bst_node* right;
}bst_node;

typedef struct bst{
    bst_node* root;
}bst;

bst_node* create_node(int data);
bst* init_tree();
void insert(bst* tree, int data);
void insert(bst_node* new_node, bst_node* nod);
bst_node* search(int data, bst_node* tree);
void clear(bst_node*& nod);
void del_elem(bst_node*& nod, int data);
int is_leaf(bst_node* nod);
bst_node* find_bigest_min(bst_node* nod);
bst_node* find_smallest_max(bst_node* nod);
#endif