#include <iostream>

class tree_node{
public:
    tree_node *left;
    tree_node *right;
    int data;
};


class BST{

private:
    tree_node *root;
public:
    BST(): root(nullptr){};
    void print(tree_node *p);
    tree_node *remove(int key);
    tree_node *insert(int val);
    tree_node *getRoot() {return root;};
    tree_node *max(tree_node *root);
    tree_node *min(tree_node *root);
    int countLeafs(tree_node *root);
    bool search(int val);
};



tree_node *BST::insert(int val)
{
    // create new node
    tree_node *newNode = new tree_node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    //empty tree
    if(root==NULL)
    {
        root = newNode;
        return root;
    }
    
    tree_node *curr = root;
    tree_node *prev;

    //find correct position for new val, keep track of previous
    // so when curr is NULL the prev is kept track of
    while(curr)
    {
        prev = curr;
        if(val < curr->data)
            curr = curr->left;
        else if (val > curr->data)
            curr = curr->right;
        else
            return curr;
    }

    // if the val is less, insert to left subtree
    // if the val is larger, insert to right subtree
    if(val < prev->data)
        prev->left = newNode;
    else if( val > prev->data)
        prev->right = newNode;
    return newNode;

}

tree_node *BST::min(tree_node *sub_tree)
{
    tree_node *curr = sub_tree;
    while(curr->left)
        curr = curr->left;
    return curr;
}

tree_node *BST::max(tree_node *sub_tree)
{
    tree_node *curr = sub_tree;
    while(curr->right)
        curr = curr->right;
    
    return curr;
}


void BST::print(tree_node *root)
{
    if(root==NULL)
        return;

    print(root->left);
    std::cout << root->data << " ";
    print(root->right);
}

int BST::countLeafs(tree_node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    return countLeafs(root->left) + countLeafs(root->right);
}

bool BST::search(int val)
{
    tree_node *curr = root;
    while(curr)
    {
        if(val < curr->data)
            curr = curr->left;
        else if(val > curr->data)
            curr = curr->right;
        else
            return true;
    }
    return false;
}


tree_node* BST::remove(int key)
{
    tree_node* curr = root;
    tree_node* prev = NULL;
 
    // Check if the key is actually
    // present in the BST.
    // the variable prev points to
    // the parent of the key to be deleted.
    while (curr != NULL && curr->data != key) {
        prev = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
 
    if (curr == NULL) {
        return root;
    }
 
    // Check if the node to be
    // deleted has atmost one child.
    if (curr->left == NULL || curr->right == NULL) {
 
        // newCurr will replace
        // the node to be deleted.
        tree_node* newCurr;
 
        // if the left child does not exist.
        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;
 
        // check if the node to
        // be deleted is the root.
        if (prev == NULL)
            return newCurr;
 
        // check if the node to be deleted
        // is prev's left or right child
        // and then replace this with newCurr
        if (curr == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;
 
        // free memory of the
        // node to be deleted.
        delete (curr);
    }
 
    // node to be deleted has
    // two children.
    else {
        tree_node* p = NULL;
        tree_node* temp;
 
        // Compute the inorder successor
        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }
 
        // check if the parent of the inorder
        // successor is the curr or not(i.e. curr=
        // the node which has the same data as
        // the given data by the user to be
        // deleted). if it isn't, then make the
        // the left child of its parent equal to
        // the inorder successor'd right child.
        if (p != NULL)
            p->left = temp->right;
 
        // if the inorder successor was the
        // curr (i.e. curr = the node which has the
        // same data as the given data by the
        // user to be deleted), then make the
        // right child of the node to be
        // deleted equal to the right child of
        // the inorder successor.
        else
            curr->right = temp->right;
 
        curr->data = temp->data;
        delete temp;
    }
    return root;
}