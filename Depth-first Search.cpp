#include <vector>

/*
You're given a Node class that has a name and an array of optional children nodes. When put together, nodes form an acyclic tree-like structure.

Implement the depthFirstSearch method on the Node class, which takes in an empty array, traverses the tree using the Depth-first Search approach 
(specifically navigating the tree from left to right), stores all of the nodes' names in the input array, and returns it.

Sample Input:
graph = A
     /  |  \
    B   C   D
   / \     / \
  E   F   G   H
     / \   \
    I   J   K
    
Sample Output:
["A", "B", "E", "F", "I", "J", "C", "D", "G", "K", "H"]
*/


using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string> *array) {
		array->push_back(name);
		
		for(int i=0; i<children.size(); i++)
		{
			children[i]->depthFirstSearch(array);
		}
    
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};


int main()
{
  //Write your code here
  return 0;
}
