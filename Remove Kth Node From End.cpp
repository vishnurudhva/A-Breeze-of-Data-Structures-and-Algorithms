#include <vector>

/*
Write a function that takes in the head of a Singly Linked List and an integer k and removes the kth node from the end of the list.

The removal should be done in place, meaning that the original data structure should be mutated (no new structure should be created).

Furthermore, the input head of the linked list should remain the head of the linked list after the removal is done, even if the head is the node that's supposed to be removed. 
In other words, if the head is the node that's supposed to be removed, your function should simply mutate its value and next pointer.

Note that your function doesn't need to return anything.

You can assume that the input Linked List will always have at least two nodes and, more specifically, at least k nodes.

Each LinkedList node has an integer value as well as a next node pointing to the next node in the list or to None / null if it's the tail of the list.

Sample Input
head = 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 // the head node with value 0
k = 4
Sample Output
// No output required.
// The 4th node from the end of the list (the node with value 6) is removed.
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 7 -> 8 -> 9
*/


using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};
void remove(LinkedList *node, LinkedList *head) {
	LinkedList *temp = head;
	if(node == head){
		head->value = head->next->value;
		head->next = head->next->next;
		return;
	}
	while(temp->next != NULL && temp->next != node)
			temp = temp->next;
	temp->next = temp->next->next;
}

void removeKthNodeFromEnd(LinkedList *head, int k) {
  LinkedList* temp = head;
	int count = 0;
	while(temp != NULL){
		temp = temp->next;
		count++;
	}
	count -= k;
	temp = head;
	while(count--) temp = temp->next;
	remove(temp, head);
}
