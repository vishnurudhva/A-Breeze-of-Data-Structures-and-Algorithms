#include <vector>

/*
Write a function that takes in an array of strings and groups anagrams together.

Anagrams are strings made up of exactly the same letters, where order doesn't matter. For example, "cinema" and "iceman" are anagrams; similarly, "foo" and "ofo" are anagrams.

Your function should return a list of anagram groups in no particular order.

Sample Input
words = ["yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp"]
Sample Output
[["yo", "oy"], ["flop", "olfp"], ["act", "tac", "cat"], ["foo"]]
*/

using namespace std;
struct grpAnag{
	string name;
	vector<string> res;
};
vector<vector<string>> groupAnagrams(vector<string> words) {
	struct grpAnag result[words.size()];
	map<string, string> verify;
	for(int i=0; i<words.size(); i++){
		string str = words[i];
		sort(words[i].begin(), words[i].end());
		verify[str] = words[i];
	}
	map<string, string>::iterator itr;
	int i=0, flag=0, k;
	for(itr = verify.begin(); itr!=verify.end(); itr++){
		for(int j=0; j<i; j++)
			if(itr->second == result[j].name){
				flag=1;
				k=j;
				break;
			}
		if(flag == 0){
			result[i].name = itr->second;
			result[i].res.push_back(itr->first);
			i++;
		}else{
			result[k].res.push_back(itr->first);
		}
		flag=0;
	}
	vector<vector<string>> ans(i);
	
	for(int j=0; j<i; j++){
		for(int k=0; k<result[j].res.size(); k++){
			ans[j].push_back(result[j].res[k]);
		}
	}
	return ans;
}

int main()
{
  //Write your code here
  return 0;
}
