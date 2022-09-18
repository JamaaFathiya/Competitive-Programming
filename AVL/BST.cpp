#include "BST.hpp"

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

void insert(bst* tree, int data){
    bst_node* n = create_node(data);
    if (n){
        if (!tree->root)
            tree->root = n;
        else
            insert(n, tree->root);
    }
}

int is_leaf(bst_node* nod){
    return (!nod->left && !nod->right);
}

void insert(bst_node* new_node, bst_node* nod){
    if (new_node->data > nod->data)
    {
        if (!nod->right)
           nod->right = new_node;
        else
           insert(new_node, nod->right);
    }
    else if (new_node->data < nod->data)
    {
        if (!nod->left)
            nod->left = new_node;
        else
            insert(new_node, nod->left);
    }
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

bst_node* find_bigest_min(bst_node* nod){

    while(nod->right)
        nod = nod->right;
    return nod;
}

bst_node* find_smallest_max(bst_node* nod){

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
            bst_node* tmp = find_bigest_min(nod->left);
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

void  inOrderTraverse( const bst_node* node, void ( *f )( int ) ) {
    if ( node ) {
        inOrderTraverse( node->left, f );
        f( node->data );
        inOrderTraverse( node->right, f );
    }
}

void preOrderTraverse( const bst_node* node, void ( *f )( int ) ) {
    if ( node ) {
        f( node->data );
        preOrderTraverse( node->left, f );
        preOrderTraverse( node->right, f );
    }
}

void  postOrderTraverse( const bst_node* node, void ( *f )( int ) ) {
    if ( node ) {
        postOrderTraverse( node->left, f );
        postOrderTraverse( node->right, f );
        f( node->data );
    }
}

using namespace std;

int main( void )
{
    bst* t = init_tree();

    insert(t, 11 );
    insert(t, 7 );
    insert(t, 9 );
    insert(t, 15 );
    insert(t, 105 );   insert(t, 10005 );   insert(t, 15831 );  insert(t, 24615 );   insert(t, 100315 );   insert(t, 17515 );   insert(t, 123455 );   insert(t, 45215 );   insert(t, 15743 );   insert(t, 666615 );   insert(t, 165 );   insert(t, 415 );   insert(t, 1115 );   insert(t, 1522 );   insert(t, 152 );   insert(t, 157 );   insert(t, 915 );   insert(t, 1599 );   insert(t, 15568 );   insert(t, 15000 );   insert(t, 1500000 );

    // preOrderTraverse( t->root, printData );
    del_elem(t->root, 123455 );
    preOrderTraverse( t->root, printData );
    clear(t->root);
    preOrderTraverse( t->root, printData );
    delete t;
}
