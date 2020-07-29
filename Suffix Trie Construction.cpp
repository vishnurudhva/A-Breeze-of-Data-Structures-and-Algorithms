#include <unordered_map>

/*
Write a SuffixTrie class for a Suffix-Trie-like data structure. The class should have a root property set to be the root node of the trie and should support:

- Creating the trie from a string; this will be done by calling the populateSuffixTrieFrom method upon class instantiation, which should populate the root of the class.
- Searching for strings in the trie.
Note that every string added to the trie should end with the special endSymbol character: "*".


Sample Input (for creation)
string = "babc"
Sample Output (for creation)
The structure below is the root of the trie.
{
  "c": {"*": true},
  "b": {
    "c": {"*": true},
    "a": {"b": {"c": {"*": true}}},
  },
  "a": {"b": {"c": {"*": true}}},
}
Sample Input (for searching in the suffix trie above)
string = "abc"
Sample Output (for searching in the suffix trie above)
true
*/

using namespace std;

class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
  TrieNode *root;
  char endSymbol;

  SuffixTrie(string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

  void populateSuffixTrieFrom(string str) {
	for(int i=0; i<str.length(); i++) insertSubs(i, str);
  }

  void insertSubs(int i, string str)
  {
	TrieNode *temp = root;
	for(int j = i; j < str.length(); j++){
		if(temp->children.find(str[j]) == temp->children.end())
		{
			TrieNode *node = new TrieNode();
			temp->children.insert({str[j], node});
		}
		temp = temp->children[str[j]];
	}
	temp->children.insert({endSymbol, NULL});
  }

  bool contains(string str) {
    TrieNode *temp = root;
	for(char letter: str){
		if(temp->children.find(letter) == temp->children.end()) return false;
		temp = temp->children[letter];
	}
	return temp->children.find(endSymbol) != temp->children.end();
  }
};
