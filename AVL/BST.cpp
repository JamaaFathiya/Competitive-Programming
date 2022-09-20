#include "AVL.hpp"

using namespace std;

bst_node* create_node(int data){
    bst_node* n = new bst_node;
    if (!n)
        return NULL;
    else
    {
        n->data = data;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

bst* init_tree(){
    bst* t = new bst;
    t->root = NULL;
    return t;
}


int is_leaf(bst_node* nod){
    return (!nod->left && !nod->right);
}

void insert(int data, bst_node*& nod){
    if (!nod){
        nod = create_node(data);
        return;
    }
    else if(data > nod->data)
        insert(data, nod->right);
    else if (data < nod->data)
        insert(data, nod->left);
}

bst_node* search(int data, bst_node *nod){
    if (nod){
        if (nod->data == data) {
            return nod;
        }
        else if (data > nod->data)
            return (search(data, nod->right));
        else if (data < nod->data)
            return (search(data, nod->left));
    }
    return NULL;
}

void clear(bst_node* &nod){
    if (!nod)
        return;
    if (nod && is_leaf(nod))
        delete nod;
    else
    {
        clear(nod->right);
        clear(nod->left);
        delete nod;
        nod = NULL;
    }
}

bst_node* successor(bst_node* nod){

    while(nod->right)
        nod = nod->right;
    return nod;
}

bst_node* predeccessor(bst_node* nod){

    while(nod->left)
        nod = nod->left;
    return nod;
}


void del_elem(bst_node*& nod, int data){
    if(!nod)
        return ;
    else if (data <nod->data) {
        del_elem(nod->left, data);
    }
    else if (data > nod->data) {
        del_elem(nod->right, data);
    }
    else{
        if (is_leaf(nod)){
            delete nod;
            nod = NULL;
        }
        else if (nod->left && nod->right){
            bst_node* tmp = successor(nod->left);
            nod->data = (tmp->data);
            del_elem(nod->left, tmp->data);
        }
        else {
            bst_node* child = (nod->left ? nod->left : nod->right);
            bst_node* tmp = nod;
            nod = child;
            delete tmp;
        }
    }
}


void        printData( int data ) { 
    std::cout << data << " " << std::endl;
}

// void  inOrderTraverse( const bst_node* node, void ( *f )( int , AVL) ) {
//     if ( node ) {
//         inOrderTraverse( node->left, f );
//         f( node->data );
//         inOrderTraverse( node->right, f );
//     }
// }

void preOrderTraverse( const bst_node* node, void ( *f )( bst_node*  , AVL t), AVL t) {
    if ( node ) {
        f( const_cast <bst_node *> (node) , t);
        preOrderTraverse( node->left, f , t);
        preOrderTraverse( node->right, f , t);
    }
}

void preOrderTraverse( const bst_node* node, void ( *f )( int)) {
    if ( node ) {
        f(node->data);
        preOrderTraverse( node->left, f);
        preOrderTraverse( node->right, f);
    }
}

// void  postOrderTraverse( const bst_node* node, void ( *f )( int ) ) {
//     if ( node ) {
//         postOrderTraverse( node->left, f );
//         postOrderTraverse( node->right, f );
//         f( node->data );
//     }
// }
