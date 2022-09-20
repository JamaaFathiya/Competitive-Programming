#include "AVL.hpp"

AVL::AVL()
{
    // std::cout << "constructor" << std::endl;
}

AVL::~AVL(){
    // std::cout << "destructor" << std::endl;
}

int AVL::height(bst_node* node){
    if(!node)
        return 0; // the accurate return value is -1 but I choose 0 to obtain a correct balence factor easily
    return(std::max(height(node->left), height(node->right)) + 1);
}

int AVL::balence_factor(bst_node* node){
    return (this->height(node->left) - this->height(node->right));
}

int AVL::balenced(bst_node* node){
    int node_h = this->balence_factor(node);
    if (node_h == 2){
        int left = this->balence_factor(node->left);
        switch (left)
        {
        case 1:
            return Left_Left_weighted;
        case -1:
            return Left_Right_weighted;
        }
    }
    else if (node_h == -2){
        int right = this->balence_factor(node->right);
        switch (right)
        {
        case -1:
            return Right_Right_weighted;
        case 1:
            return Right_Left_weighted;
        }
    }
        return Balenced;
}

void printBalenceState(bst_node* node, AVL t){
    int bf = t.balenced(node);
    std::cout << " data: " << node->data ;
    switch (bf)
    {
    case Right_Right_weighted:
        std::cout << " Right_Right_weighted" << std::endl;
        break;
    case Right_Left_weighted:
        std::cout << " Right_Left_weighted " << std::endl;
        break;
    case Left_Left_weighted:
        std::cout << " Left_Left_weighted " << std::endl;
        break;
    case  Left_Right_weighted:
        std::cout << "  Left_Right_weighted " << std::endl;
        break;
    default:
        std::cout << " Balenced " << std::endl;
        break;
    }
}

/*-------------- Rotations ----------------*/

void    AVL::right_rotate(bst_node*& node){
    bst_node* pivot = node;
    bst_node* l_child = node->left;

    pivot->left = l_child->right;
    l_child->right = pivot;
    node = l_child;
}

void    AVL::left_rotate(bst_node*& node){
        bst_node* pivot = node;
        bst_node* r_child = node->right;
        
        pivot->right = r_child->left;
        r_child->left = pivot;
        node = r_child;
}

void    AVL::right_left_rotate(bst_node*& node){
        this->right_rotate(node->right);
        this->left_rotate(node);
}

void    AVL::left_right_rotate(bst_node*& node){
        this->left_rotate(node->left);
        this->right_rotate(node);
}


void    AVL::balence(bst_node*& node){
    int balenceStatus = this->balenced(node);
    // std::cout << "bf: " << balenceFactor << std::endl;
    switch (balenceStatus)
    {
        case Left_Left_weighted:
        {
            this->right_rotate(node);
            break;
        }
        case Right_Right_weighted:
        {
            this->left_rotate(node);
            break;
        }
        case  Right_Left_weighted:
        {
            this->right_left_rotate(node);
            break;
        }
        case  Left_Right_weighted:
        {
            this->left_right_rotate(node);
            break;
        }
    }
}

void    AVL::insert_and_Balence(bst_node*& node, int data){
    insert(data, node);
    this->balence(node);
}

void    AVL::delete_and_Balence(bst_node*& node, int data){
    del_elem(node, data);
    this->balence(node);
}

void    AVL::exist(int data){
    if (search(data, this->tree->root))
        std::cout << "exist" << std::endl;
    else
        std::cout <<  " not found! "<< std::endl;   
}