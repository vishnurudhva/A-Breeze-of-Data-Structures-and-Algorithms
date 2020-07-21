#include<bits/stdc++.h>
using namespace std;

/*
Write a function that takes in a Binary Tree and returns a list of its branch sums ordered from leftmost branch sum to rightmost branch sum.

A branch sum is the sum of all values in a Binary Tree branch. A Binary Tree branch is a path of nodes in a tree that starts at the root node and ends at any leaf node.

Each BinaryTree node has an integer value, a left child node, and a right child node. Children nodes can either be BinaryTree nodes themselves or None / null.

Sample Input:

tree =     1
        /     \
       2       3
     /   \    /  \
    4     5  6    7
  /   \  /
 8    9 10
 
Sample Output:
[15, 16, 18, 10, 11]
*/


// This is the class of the input root. Do not edit it.
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
void calculateBranchSums(BinaryTree *root, int currentSum, vector<int> &sums);


vector<int> branchSums(BinaryTree *root) {
  vector<int> sums;
  calculateBranchSums(root, 0, sums);
  return sums;
}

void calculateBranchSums(BinaryTree *root, int currentSum, vector<int> &sums){
  if(root == NULL) return;

  int newCurrentSum = currentSum + root->value;
  if(root->left == NULL && root->right == NULL)
  {
    sums.push_back(newCurrentSum);
    return;
  }
  calculateBranchSums(root->left, newCurrentSum, sums);
  calculateBranchSums(root->right, newCurrentSum, sums);
}

int main()
{
  BinaryTree *head = new BinaryTree(1);
  head->left = new BinaryTree(2);
  head->right = new BinaryTree(3);

  head->left->left = new BinaryTree(4);
  head->left->right = new BinaryTree(5);

  head->right->left = new BinaryTree(6);
  head->right->right = new BinaryTree(7);

  head->left->left->left = new BinaryTree(8);
  head->left->left->right = new BinaryTree(9);

  head->left->right->left = new BinaryTree(10);

  vector<int> sums = branchSums(head);

  for(int i=0; i<sums.size(); i++)
    cout<<sums[i]<<", ";
  
	return 0;
}
