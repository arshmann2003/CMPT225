#include <iostream>

class node
{
    public:
        node *right;
        node *left;
        int data;
        node(node *right, node *left, int data): 
            right(right), left(left), data(data){};

        node(int data): right(NULL), left(NULL), data(data){};
};


class Tree
{
    private:
        node *root;
        int size;

        void print_helper(node *root)
        {
            if(root==NULL)
                return;

            std::cout << " "<< root->data;
            print_helper(root->left);
            print_helper(root->right);
        };
        int countLeafNodes_helper(node *root) 
        {
            if(root==NULL)
                return 0;
            if(root->left==NULL && root->right==NULL)
                return 1;
            
            return countLeafNodes_helper(root->left) + countLeafNodes_helper(root->right);            
        }
    
    public:
        Tree(int rootVal):root(new node(rootVal)), size(1){};

        void setLeft(int val)
        {
            if(root==NULL)
            {
                throw std::logic_error("EMPTY Tree");
            }

            node *curr = root;
            while(curr->left)
            {
                curr = curr->left;
            }
            curr->left = new node(NULL, NULL, val);
            size++;
        };
        void setRight(int val)
        {
            if(root==NULL)
            {
                throw std::logic_error("EMPTY Tree");
            }

            node *curr = root;
            while(curr->right)
            {
                curr = curr->right;
            }
            curr->right = new node(NULL, NULL, val);
            size++;
        };
       
        void print()
        {
            print_helper(root);
        };  
        
        int countLeafNodes()
        {
            return countLeafNodes_helper(root);
        }


};

int main()
{
    
    Tree tree(1);

    tree.setRight(3);
    std::cout << tree.countLeafNodes();
    return 0;
}