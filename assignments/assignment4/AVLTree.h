#include <iostream>
using namespace std;

// AVL Node Clas
template <class T, class K>
class AVLTreeNode {
public:
	// Should have attributes named:
	AVLTreeNode<T, K> *parent;		// parent - pointer to parent
	AVLTreeNode<T, K> *left;		// left - pointer to left child
	AVLTreeNode<T, K> *right; 		// right - pointer to right child
	K key;						// key - node's key
	T value;					// value - node's value
	unsigned int height; 		// height - node's height
	AVLTreeNode(T value,K key):parent(NULL), left(NULL), right(NULL), key(key), value(value), height(0){};
	AVLTreeNode(): parent(NULL), left(NULL), right(NULL), height(0){};
	// Constructors ...
};



template <class T, class K>
// AVL Tree class
class AVLTree
{
private:
	// Tree attributes go here
	// Your tree MUST have a root node named root
	AVLTreeNode<T, K> *root;
	unsigned int size_;
	AVLTreeNode<T, K> *Insert_helper(AVLTreeNode<T, K> *root, K key, T val, bool rotations);
	int balanceFactor(AVLTreeNode<T, K> *node);
	AVLTreeNode<T, K> * LLrotation(AVLTreeNode<T, K> *node);
	AVLTreeNode<T,K> * RRrotation(AVLTreeNode<T, K> *node);
	unsigned int height_(AVLTreeNode<T, K> *node);
	void balance(AVLTreeNode<T, K> *node, K key);
	void copy(AVLTreeNode<T,K> *root, AVLTree<T,K> &destination);
	void delete_tree(AVLTreeNode<T,K> *root);
	AVLTreeNode<T,K> *deleteNode(AVLTreeNode<T,K> *root, K key, bool &success);
	AVLTreeNode<T,K> *minValueNode(AVLTreeNode<T,K>* node);
	AVLTreeNode<T,K> *removeRoot();

public:
	~AVLTree();		// Destructor
	AVLTree(const AVLTree<T,K> &tree); // copy constructor
	AVLTree<T,K> & operator=(const AVLTree<T,K> &tree);	// operator overload
	AVLTree():root(NULL), size_(0){};	// default constructor
	bool insert(K key, T val);		
	bool remove(K key);
	T search(K key);
	vector<T> values();	
	vector<K> keys();
	unsigned int size(){return size_;};
	void* getRoot() const { return root; }; // DO NOT REMOVE
};


//-----------------SMALL_HELPER_FUNCTIONS--------------------

int max(int a, int b)
{
    if(a>b)return a;
	return b;
}

template<class T, class K>
unsigned AVLTree<T,K>::height_(AVLTreeNode<T, K> *N)
{
	if(N==NULL)
		return 0;
	return N->height;
}

template <class T, class K>
int AVLTree<T,K>::balanceFactor(AVLTreeNode<T, K> *node)
{
	if(node==NULL)
		return 0;
	
	
	int height_left = height_(node->left);
	if(node->left==NULL)
		height_left = -1;

	int height_right = height_(node->right);
	if(node->right ==NULL)
		height_right = -1;
		
	return (height_left-height_right);
}

// --------------------------------------------------------


// --------------------DESTRUCTOR----------------------
template <class T, class K>
AVLTree<T,K>::~AVLTree()
{
	delete_tree(root);
}

template <class T, class K>
void AVLTree<T,K>::delete_tree(AVLTreeNode<T,K> *root)
{
	if(root==NULL)
		return;
	delete_tree(root->left);
	delete_tree(root->right);
	delete root;
}

// ----------------------------------------------------


// -----------------------VALUES & KEYS-----------------------------

template <class T, class K>
void insert_vals(AVLTreeNode<T,K> *node, vector<T> &vals)
{
	if(node==NULL)
		return;
	
	insert_vals(node->left, vals);
	vals.push_back(node->value);
	insert_vals(node->right, vals);
}
template <class T, class K>
void insert_keys(AVLTreeNode<T,K> *node, vector<K> &keys)
{
	if(node==NULL)
		return;
	
	insert_keys(node->left, keys);
	keys.push_back(node->key);
	insert_keys(node->right, keys);
}

template <class T, class K>
vector<T> AVLTree<T,K>::values()
{
	vector<T> vals;
	insert_vals(root, vals);
	return vals;
}

template <class T, class K>
vector<K> AVLTree<T,K>::keys()
{
	vector<K> keys;
	insert_keys(root, keys);
	return keys;
}


// -----------------------------------------------------------------



// -------------------------COPY---------------------------

template <class T, class K>
void AVLTree<T,K>::copy(AVLTreeNode<T,K> *root, AVLTree<T,K> &destination)
{
	if(root==NULL)
		return;

	destination.Insert_helper((AVLTreeNode<T,K>*)destination.getRoot(), root->key, root->value, false);	
	copy(root->left, destination);
	copy(root->right, destination);

}

template <class T, class K>
AVLTree<T,K>::AVLTree(const AVLTree<T,K> &tree)
{
	
	AVLTreeNode<T,K> *T2 = (AVLTreeNode<T,K>*)tree.getRoot();
	if(T2==NULL)
	{
		this->root = NULL;
		this->size_ = tree.size_;
	}
	if(T2!=NULL)
	{
		this->root = new AVLTreeNode<T, K>(T2->value, T2->key);
		this->size_ = tree.size_;
		copy(T2, *this);
	}
}

template <class T, class K>
AVLTree<T,K> &AVLTree<T,K>::operator=(const AVLTree<T,K> &tree)
{
	AVLTreeNode<T,K> *T2 = (AVLTreeNode<T,K>*)tree.getRoot();
	if(T2==NULL)
	{
		this->root = NULL;
	}
	if(T2!=NULL)
	{
		this->root = new AVLTreeNode<T,K>(T2->value, T2->key);
		copy(T2, *this);
	}
	this->size_ = tree.size_;
	return *this;
}
// ------------------------------------------------------


// ------------------------ROTATIONS------------------------

//left left roatation
template <class T, class K>
AVLTreeNode<T, K> * AVLTree<T, K>::LLrotation(AVLTreeNode<T, K> *old)
{
	
	AVLTreeNode<T, K> *new_par = old->left;
	AVLTreeNode<T, K> *subtree  = new_par->right;
	new_par->right = old;
	old->left = subtree;

	int old_left_height = height_(old->left);
	if(old->left==NULL)
		old_left_height = -1;
	int old_right_height = height_(old->right);
	if(old->right==NULL)
		old_right_height = -1;

	old->height = max(old_left_height, old_right_height) + 1;
    

	int new_par_left = height_(new_par->left);
	if(new_par->left==NULL)
		new_par_left = -1;
	int new_par_right = height_(new_par->right);
	if(new_par->right==NULL)
		new_par_right = -1;
	
	new_par->height = max(new_par_left, new_par_right) + 1;


	if(new_par->right==root)
		root = new_par;
	return new_par;
}

template <class T, class K>
AVLTreeNode<T,K> * AVLTree<T, K>::RRrotation(AVLTreeNode<T, K> *node)
{
	AVLTreeNode<T,K> *new_par = node->right;
	AVLTreeNode<T,K> *subtree = new_par->left;
	new_par->left = node;
	node->right = subtree;

	int node_left_height = height_(node->left);
	if(node->left==NULL)
		node_left_height = -1;
	
	int node_right_height = height_(node->right);
	if(node->right==NULL)
		node_right_height = -1;

	node->height = max(node_left_height, node_right_height) + 1;


	int new_par_left = height_(new_par->left);
	if(new_par->left==NULL)
		new_par_left = -1;

	int new_par_right = height_(new_par->right);
	if(new_par->right==NULL)
		new_par_right = -1;

	new_par->height = max(new_par_left, new_par_right) + 1;


	if(new_par->left==root)
		root = new_par;
	return new_par;
}

// ---------------------------------------------------------

//---------------------SEARCH-------------------------

template <class T, class K>
T AVLTree<T, K>::search(K key)
{
	AVLTreeNode<T,K> *curr = root;
	while(curr)
	{
		if(key < curr->key)
			curr = curr->left;
		else if(key > curr->key)
			curr = curr->right;
		else
			return curr->value;
	}
	throw std::runtime_error("KEY NOT FOUND");
}

//----------------------------------------------------

// -----------------------INSERTION------------------------

template <class T, class K>
AVLTreeNode<T, K> * AVLTree<T, K>::Insert_helper(AVLTreeNode<T, K> *node, K key, T val, bool rotations)
{
	
	if(node==NULL){
		AVLTreeNode<T, K>* newNode = new AVLTreeNode<T,K>(val, key);
		if(root==NULL)
			root = newNode;
		return newNode;
	}
	if(key < node->key)
	{
		AVLTreeNode<T, K> *l = Insert_helper(node->left, key, val, rotations);
		if(l==NULL)
			return NULL;
		node->left = l;
		l->parent = node;
	}
	else if(key > node->key){
		AVLTreeNode<T, K> *r = Insert_helper(node->right, key, val, rotations);
		if(r==NULL)
			return NULL;
		node->right = r;
		r->parent = node;
	}
	else
		return NULL;

	int node_left_height = height_(node->left);
	if(node->left==NULL)
		node_left_height = -1;
	int node_right_height = height_(node->right);
	if(node->right==NULL)
		node_right_height = -1;

	node->height =  max(node_right_height, node_left_height) + 1;	
	
 	int bf = balanceFactor(node);
	// ROTATIONS IF NECESSARY -- NOT NEEDED FOR COPY CONSTRUCTORS
	if(rotations)
	{	
		if(bf > 1 && key < node->left->key)
			return LLrotation(node);	
		if(bf < -1 && key > node->right->key)
			return RRrotation(node);
		if(bf > 1 && key > node->left->key)
		{
			node->left = RRrotation(node->left);
			return LLrotation(node);
		}
		//right left case
		if(bf < -1 && key < node->right->key)
		{
			node->right = LLrotation(node->right);
			return RRrotation(node);
		}
	}
	return node;
}


template <class T, class K>
bool AVLTree<T, K>::insert(K key, T val)
{
	AVLTreeNode<T,K> *node = Insert_helper(root, key, val, true);
	if(!node)	
		return false;
	size_++;
	return true;
}

// -----------------------------------------------------------



// ----------------DELETE-----------------------

template <class T, class K>
AVLTreeNode<T,K>* AVLTree<T,K>::minValueNode(AVLTreeNode<T,K>* node)
{
    AVLTreeNode<T,K>* curr = node;
 
    while (curr && curr->left != NULL)
        curr = curr->left;
 
    return curr;
}


template <class T, class K>
AVLTreeNode<T,K>* AVLTree<T,K>::deleteNode(AVLTreeNode<T,K>* node, K key, bool &success)
{
    // base case
    if (node == NULL)
        return node;

    if (key < node->key)
        node->left = deleteNode(node->left, key, success);
 
    else if (key > node->key)
	{
        node->right = deleteNode(node->right, key, success);

	}
 
    else {
		success=true;
       	if (node->left==NULL && node->right==NULL){
			delete node;
			if(root->key==key)
				root = NULL;
			return NULL;
		}

        else if (node->left == NULL) {
            AVLTreeNode<T,K>* temp = node->right;
            delete node;
			if(root->key==key)
				root = temp;
			
            return temp;
        }
        else if (node->right == NULL) {
            AVLTreeNode<T,K>* temp = node->left;
            delete node;			
			if(root->key== key)
				root = temp;
			
            return temp;
        }
		else
		{
			AVLTreeNode<T,K>* temp = minValueNode(node->right);	
			K temp_k = temp->key;
			T temp_t = temp->value;
			node->right = deleteNode(node->right, temp->key, success);
			node->key = temp_k;
			node->value = temp_t;
		}
    }
	if(node==NULL)
		return node;
	int node_left_height = height_(node->left);
	if(node->left==NULL)
		node_left_height = -1;
	int node_right_height = height_(node->right);
	if(node->right==NULL)
		node_right_height = -1;
	

	node->height = max(node_left_height , node_right_height) + 1;
	
	// BALANCING IF REQUIRED
	int bf = balanceFactor(node);

	if (bf > 1 && balanceFactor(node->left) >= 0)
        return LLrotation(node);
	
	if (bf > 1 && balanceFactor(node->left) < 0)
    {
        node->left = RRrotation(node->left);
        return LLrotation(node);
    }
    if (bf < -1 && balanceFactor(node->right) <= 0)
        return RRrotation(node);
    
	if (bf < -1 && balanceFactor(node->right) > 0)
    {
        node->right = LLrotation(node->right);
        return RRrotation(node);
    }

    return node;
}


template <class T, class K>
bool AVLTree<T,K>::remove(K key)
{	
	bool check = false;
	deleteNode(root, key, check);
	
	if(check == true)
	{
		size_--;
		return true;
	}
	return false;
}
