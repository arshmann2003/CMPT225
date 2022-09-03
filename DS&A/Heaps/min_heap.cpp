#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int val):left(NULL), right(NULL), data(val){};
};


class BST{
    private:
        node *root;
        node *insert_helper(node *root, int val);
        void print_(node *root);
    public:
        void print();
        int sum_even();
        void insert(int val);
        BST():root(NULL){};
        ~BST(){delete root;};
    
};

void BST::print()
{
    node *curr = root;
    print_(curr);
}

void BST::print_(node *root)
{
    if(root==NULL)
        return;
    
    print_(root->left);
    cout << root->data << " ";
    print_(root->right);

}

node *BST::insert_helper(node *root, int val)
{
    if(root==NULL)
        return new node(val);
    
    if(val > root->data)
        root->right = insert_helper(root->right, val);
    else    
        root->left = insert_helper(root->left, val);

    return root;

}

void BST::insert(int val)
{
    if(root==NULL)
        root = new node(val);
    else
        insert_helper(root, val);
}

int
int main()
{
    BST tree;
    tree.insert(2);
    tree.insert(100);
    tree.insert(88);
    // tree.insert(1);
    tree.print();
    return 0;
}

