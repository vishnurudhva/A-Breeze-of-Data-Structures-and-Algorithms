#include <vector>

/*
Write a BST class for a Binary Search Tree. The class should support:

- Inserting values with the insert method.
- Removing values with the remove method; this method should only remove the first instance of a given value.
- Searching for values with the contains method.
Note that you can't remove values from a single-node tree. In other words, calling the remove method on a single-node tree should simply not do anything.

Each BST node has an integer value, a left child node, and a right child node. 
A node is said to be a valid BST node if and only if it satisfies the BST property: its value is strictly greater than the values of every node to its left; 
its value is less than or equal to the values of every node to its right; and its children nodes are either valid BST nodes themselves or None / null.

Sample Usage
// Assume the following BST has already been created:
         10
       /     \
      5      15
    /   \   /   \
   2     5 13   22
 /           \
1            14

// All operations below are performed sequentially.
insert(12):   10
            /     \
           5      15
         /   \   /   \
        2     5 13   22
      /        /  \
     1        12  14

remove(10):   12
            /     \
           5      15
         /   \   /   \
        2     5 13   22
      /           \
     1            14

contains(15): true
*/

using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = NULL;
    right = NULL;
  }

  BST &insert(int val) {
    if(this->value > val){
		if(this->left != NULL)
		{
			this->left->insert(val);
		}
		else
		{
			this->left = new BST(val);
		}
	}else{
		if(this->right != NULL)
		{
			this->right->insert(val);
		}
		else
		{
			this->right = new BST(val);
		}
	}
    return *this;
  }

  bool contains(int val) {
	if(this->value == val) return true;
    if(this->value > val)
	{
		if(this->left != NULL)
			return this->left->contains(val);
		else
			return false;
	}
	else
	{
		if(this->right != NULL)
			return this->right->contains(val);
		else
			return false;
	}
  }


  BST &remove(int val, BST *parent=NULL) {
    if(val < value){
			if(left != NULL)
				left->remove(val, this);
		}else if(val > value){
			if(right != NULL)
				right->remove(val, this);
		}else{
			if(left != NULL && right != NULL)
			{
				value = right->getMin();
				right->remove(value, this);
			}else if(parent == NULL){
				if(left != NULL){
					value = left->value;
					right = left->right;
					left = left->left;
				}else if(right != NULL){
					value = right->value;
					left = right->left;
					right = right->right;
				}else{
					
				}
			}else if(parent->left == this){
				parent->left = left != NULL ? left : right;
			}else if(parent->right == this){
				parent->right = left != NULL ? left : right;
			}
		}
    return *this;
  }
	
	int getMin(){
		if(left == NULL) return value;
		else return left->getMin();
	}
};
