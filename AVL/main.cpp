#include "AVL.hpp"

using namespace std;

int main( void )
{
    AVL avl;
    avl.tree = init_tree(); 

    insert(45, avl.tree->root );
    insert(30,avl.tree->root);
    insert(40,avl.tree->root);
    // insert(2,avl.tree->root);
    // preOrderTraverse( t->root, printData ); 
    // del_elem(avl.tree->root, 123455 );
    // preOrderTraverse( avl.tree->root, printBalenceState , avl);
    cout << " before balancing " << endl;
    preOrderTraverse( avl.tree->root, printData );
    clear(avl.tree->root);
    avl.insert_and_Balence( avl.tree->root, 45);
    avl.insert_and_Balence( avl.tree->root, 30);
    avl.insert_and_Balence( avl.tree->root, 40);
    cout << " after balancing " << endl;
    preOrderTraverse( avl.tree->root, printData );
    clear(avl.tree->root);
    // cout << "height: " << avl.height(avl.tree->root) << endl;
    // cout << "balence factor: " << avl.balence_factor(avl.tree->root);
    delete avl.tree;
}