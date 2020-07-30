#include <vector>

/*
You're given three inputs, all of which are instances of an AncestralTree class that have an ancestor property pointing to their youngest ancestor. The first input is the top ancestor in an ancestral tree (i.e., the only instance that has no ancestor--its ancestor property points to None / null), and the other two inputs are descendants in the ancestral tree.

Write a function that returns the youngest common ancestor to the two descendants.

Note that a descendant is considered its own ancestor. So in the simple ancestral tree below, the youngest common ancestor to nodes A and B is node A.

// The youngest common ancestor to nodes A and B is node A.
  A
 /
B
Sample Input
// The nodes are from the ancestral tree below.
topAncestor = node A
descendantOne = node E
descendantTwo = node I
          A
       /     \
      B       C
    /   \   /   \
   D     E F     G
 /   \
H     I
Sample Output
node B
*/

using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = NULL;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
	int count, countOne = 0, countTwo = 0;
	AncestralTree *temp = descendantOne;
	while(temp != topAncestor && ++countOne) temp = temp->ancestor;
	temp = descendantTwo;
	while(temp != topAncestor && ++countTwo) temp = temp->ancestor;
	if(countOne > countTwo){
		count = countOne - countTwo;
		while(count--) descendantOne = descendantOne->ancestor;
	}else{
		count = countTwo - countOne;
		while(count--) descendantTwo = descendantTwo->ancestor;		
	}
	
	while(descendantOne->ancestor != NULL && descendantOne != descendantTwo){
		descendantOne = descendantOne->ancestor;
		descendantTwo = descendantTwo->ancestor;
	}
	
  return descendantOne;
}
