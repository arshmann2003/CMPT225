#include "BST.hpp"
#include "stack.hpp"


int sum(tree_node *root)
{
    if(root==nullptr)
        return 0;
    return root->data + sum(root->left) + sum(root->right);
}

void iterative_inorder(tree_node *t)
{
    Stack<tree_node*> stack;

    while(t!=nullptr || !stack.isEmpty())
    {

        if(t!=nullptr)
        {
            stack.push(t);
            t = t->left;
        }
        else
        {
            t = stack.pop();
            std::cout << t->data << " ";
            t = t->right;
        }
    }
}


int main()
{

    BST tree;

    tree.insert(5);
    tree.insert(9);
    tree.insert(8);
    tree.insert(10);
    tree.insert(15);
    tree.insert(3);
    tree.insert(2); 
    tree.insert(4); 
    
    tree.remove(10);
    tree.remove(5);
    
        
    tree.print(tree.getRoot());
    return 0;
}

