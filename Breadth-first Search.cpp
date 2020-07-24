#include <vector>
#include <deque>

/*
You're given a Node class that has a name and an array of optional children nodes. When put together, nodes form an acyclic tree-like structure.

Implement the breadthFirstSearch method on the Node class, which takes in an empty array, traverses the tree using the Breadth-first Search approach (specifically navigating the tree from left to right), stores all of the nodes' names in the input array, and returns it.

Sample Input
graph = A
     /  |  \
    B   C   D
   / \     / \
  E   F   G   H
     / \   \
    I   J   K
    
Sample Output
["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"]
*/

using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }
	
  vector<string> breadthFirstSearch(vector<string> *array) {
    deque<Node*> queue{this};
		while(!queue.empty()){
			for(int i=0; i<queue.front()->children.size(); i++){
				queue.push_back(queue.front()->children[i]);
			}
			array->push_back(queue.front()->name);
			queue.pop_front();
		}
		return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
