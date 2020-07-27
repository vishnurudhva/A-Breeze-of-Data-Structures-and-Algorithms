using namespace std;

/*
Write a DoublyLinkedList class that has a head and a tail, both of which point to either a linked list Node or None / null. The class should support:

- Setting the head and tail of the linked list.
- Inserting nodes before and after other nodes as well as at given positions.
- Removing given nodes and removing nodes with given values;
- Searching for nodes with given values.
Each Node has an integer value as well as a prev node and a next node, both of which can point to either another node or None / null.

Sample Usage
// Assume the following linked list has already been created:
1 <-> 2 <-> 3 <-> 4 <-> 5
setHead(4): 4 <-> 1 <-> 2 <-> 3 <-> 5 // set the existing node with value 4 as the head
setTail(6): 4 <-> 1 <-> 2 <-> 3 <-> 5 <-> 6 // set the existing node with value 6 as the tail
insertBefore(6, 3): 4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6 // move the existing node with value 3 before the existing node with value 6
insertAfter(6, 3): 4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6 <-> 3 // insert a new node with value 3 after the existing node with value 6
insertAtPosition(1, 3): 3 <-> 4 <-> 1 <-> 2 <-> 5 <-> 3 <-> 6 <-> 3 // insert a new node with value 3 in position 1
removeNodesWithValue(3): 4 <-> 1 <-> 2 <-> 5 <-> 6 // remove all nodes with value 3
remove(2): 4 <-> 1 <-> 5 <-> 6 // remove the existing node with value 2
containsNodeWithValue(5): true
*/

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
};

class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = NULL;
    tail = NULL;
  }

  void setHead(Node *node) {
		if(head == NULL){
			head = node;
			tail = node;
			return;
		}
		insertBefore(head, node);
  }

  void setTail(Node *node) {
		if(tail == NULL){
			setHead(node);
			return;
		}
		insertAfter(tail, node);
  }

  void insertBefore(Node *node, Node *nodeToInsert) {
		if (nodeToInsert == head && nodeToInsert == tail) return;
		remove(nodeToInsert);
		nodeToInsert->prev = node->prev;
		nodeToInsert->next = node;
		if(node->prev == NULL) head = nodeToInsert;
		else node->prev->next = nodeToInsert;
		node->prev = nodeToInsert;
}

  void insertAfter(Node *node, Node *nodeToInsert) {
    if(nodeToInsert == head && nodeToInsert == tail) return;
		remove(nodeToInsert);
		nodeToInsert->prev = node;
		nodeToInsert->next = node->next;
		if(node->next == NULL) tail = nodeToInsert;
		else node->next->prev = nodeToInsert;
		node->next = nodeToInsert;
  }

  void insertAtPosition(int position, Node *nodeToInsert) {
		if(position == 1)
		{
			setHead(nodeToInsert);
			return;
		}
		Node *node = head;
		int cur = 1;
		while(node != NULL && cur++ != position) node = node->next;
		if(node != NULL) insertBefore(node, nodeToInsert);
		else setTail(nodeToInsert);
  }

  void removeNodesWithValue(int value) {
    Node *node = head;
		while(node != NULL){
			Node* remNode = node;
			node = node->next;
			if(remNode->value == value)
				remove(remNode);
		}
  }
	
  void remove(Node *node) {
		if(node == head)
			head = head->next;
		if(node == tail)
			tail = tail->prev;
		if(node->prev != NULL) node->prev->next = node->next;
		if(node->next != NULL) node->next->prev = node->prev;
		node->prev = NULL;
		node->next = NULL;
  }

  bool containsNodeWithValue(int value) {
    Node *temp = head;
		while(temp != NULL && temp->value != value)
			temp = temp->next;
		return temp != NULL;
  }
};
