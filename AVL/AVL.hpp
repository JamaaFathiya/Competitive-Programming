#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>

/*------------ Binary Search Tree ------------*/

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
void insert(int data, bst_node*& nod);
bst_node* search(int data, bst_node* tree);
void clear(bst_node*& nod);
void del_elem(bst_node*& nod, int data);
int is_leaf(bst_node* nod);
bst_node* successor(bst_node* nod);
bst_node* predeccessor(bst_node* nod);
void        printData( int data );
/*------------- AVL Tree --------------*/

 enum B_F{
     Balenced,
     Right_Right_weighted,
     Right_Left_weighted,
     Left_Left_weighted,
     Left_Right_weighted,
};

class AVL{
    public:
        bst *tree;
        AVL();
        ~AVL();

        int  height(bst_node* node);
        int  balence_factor(bst_node* node);
        int  balenced(bst_node* node);
        void balence(bst_node*& node);
        void left_rotate(bst_node*& node);
        void right_rotate(bst_node*& node);
        void left_right_rotate(bst_node*& node);
        void right_left_rotate(bst_node*& node);
        void insert_and_Balence(bst_node*& node, int data);
        void delete_and_Balence(bst_node*& node, int data);
        void exist(int data);
};

void printBalenceState(bst_node* node, AVL t);
void preOrderTraverse( const bst_node* node, void ( *f )( bst_node* , AVL), AVL t);
void preOrderTraverse( const bst_node* node, void ( *f )(int));
#endif