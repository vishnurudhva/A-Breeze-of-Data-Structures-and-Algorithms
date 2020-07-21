#include<bits/stdc++.h>

/*
The distance between a node in a Binary Tree and the tree's root is called the node's depth.

Write a function that takes in a Binary Tree and returns the sum of its nodes' depths.

Each BinaryTree node has an integer value, a left child node, and a right child node. Children nodes can either be BinaryTree nodes themselves or None / null.

Sample Input:

tree =    1
       /     \
      2       3
    /   \   /   \
   4     5 6     7
 /   \
8     9

Sample Output:
16
// The depth of the node with value 2 is 1.
// The depth of the node with value 3 is 1.
// The depth of the node with value 4 is 2.
// The depth of the node with value 5 is 2.
// Etc..
// Summing all of these depths yields 16.
*/


using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};


int nodeDepths(BinaryTree *root, int depth = 0) {
  if (root == NULL) return 0;
	return depth + nodeDepths(root->left, depth+1)
									+ nodeDepths(root->right, depth+1);
}


int main()
{
  //Write your code here
  return 0;
}
