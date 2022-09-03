// // Basic test program for AVL Tree
// // Author: John Edgar
// // Date: July 2022

#include <vector>
#include <iostream>
#include "AVLTree.h"
using std::cout;
using std::endl;
using std::vector;

// void a4marking();
// template <class K, class V>
// bool checkAVLTree(const AVLTree<K, V>& tree);

// int main()
// {
//     a4marking();
//     return 0;
// }

// void a4marking()
// {
//     AVLTree<int, int> aspen;

//     // Method return values
//     bool success = aspen.insert(1, 2);
//     int result = aspen.search(1);
//     checkAVLTree<int, int>(aspen);
//     success = aspen.remove(1);
//     vector<int> v2 = aspen.values();
//     vector<int> k1 = aspen.keys();
//     // AVLTree<int, int> larch(aspen);
//     // aspen = larch;

//     cout << endl << "end a4 test" << endl;
// }

// template <class K, class V>
// bool checkAVLTree(const AVLTree<K, V>& tree)
// {
//     AVLTreeNode<K, V>* nd = (AVLTreeNode<K, V>*)tree.getRoot();
//     cout << "height = " << nd->height << endl;

//     return false;
// }

template <class T, class K>
void print(AVLTreeNode<T,K> *node)
{
    if(node==NULL)
        return;
    
    print(node->left);
    cout << node->height << " ";
    print(node->right);
}

int main()
{
    AVLTree<char, int> tree;
    
    tree.insert(10,'1');
    tree.insert(2,'2');
    tree.insert(15,'3');
    tree.insert(16,'4');
    tree.insert(8,'5');
    tree.insert(4,'4');
    tree.insert(3,'3');
    

    // tree.remove(2);
    // tree.remove(4);  
    // tree.remove(15);
    // tree.remove(10);
    // tree.remove(16);
    // tree.remove(8);
    // tree.remove(3);
    
    AVLTree<char, int> tree2(tree);


    
    print((AVLTreeNode<int, int>*)tree2.getRoot());
    cout << "\n";
    print((AVLTreeNode<int, int>*)tree.getRoot());
    AVLTreeNode<int, int>*node = (AVLTreeNode<int, int>*)tree2.getRoot();
    // cout << node->key;
    // tree.search(10);

    cout << endl;
}


