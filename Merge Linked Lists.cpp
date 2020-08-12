#include <vector>
/*
Write a function that takes in the heads of two Singly Linked Lists that are in sorted order, respectively. The function should merge the lists in place (i.e., it shouldn't create a brand new list) and return the head of the merged list; the merged list should be in sorted order.

Each LinkedList node has an integer value as well as a next node pointing to the next node in the list or to None / null if it's the tail of the list.

You can assume that the input linked lists will always have at least one node; in other words, the heads will never be None / null.

Sample Input
headOne = 2 -> 6 -> 7 -> 8 // the head node with value 2
headTwo = 1 -> 3 -> 4 -> 5 -> 9 -> 10 // the head node with value 1
Sample Output
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 // the new head node with value 1
*/
using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = NULL;
  }
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
	LinkedList* One = headOne;
	LinkedList* Prev = NULL;
	LinkedList* Two = headTwo;
  while(One != NULL && Two != NULL){
		if(One->value < Two->value){
			Prev = One;
			One = One->next;
		}else{
			if(Prev != NULL)
				Prev->next = Two;
			Prev = Two;
			Two = Two->next;
			Prev->next = One;
		}
	}
	if(One == NULL)
		Prev->next = Two;
	
		
  return headOne->value < headTwo->value ? headOne : headTwo;
}
