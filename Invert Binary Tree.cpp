#include <vector>

/*
Write a function that takes in a Binary Tree and inverts it. In other words, the function should swap every left node in the tree for its corresponding right node.

Each BinaryTree node has an integer value, a left child node, and a right child node. Children nodes can either be BinaryTree nodes themselves or None / null.

Sample Input
tree =    1
       /     \
      2       3
    /   \   /   \
   4     5 6     7
 /   \
8     9
Sample Output
       1
    /     \
   3       2
 /   \   /   \
7     6 5     4
            /   \
           9     8
*/

using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
	if(tree == NULL) return;
	swap(tree->left, tree->right);
	invertBinaryTree(tree->left);
	invertBinaryTree(tree->right);
}

int main()
{
  //Write your code here
  return 0;
}
