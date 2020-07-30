#include <vector>

/*
Write a function that takes in an array of unique integers and returns an array of all permutations of those integers in no particular order.

If the input array is empty, the function should return an empty array.

Sample Input
array = [1, 2, 3]
Sample Output
[[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
*/


using namespace std;
void permutationHelper(int i, vector<int> &array, vector<vector<int>> &permutations);
vector<vector<int>> getPermutations(vector<int> array) {
  vector<vector<int>> permutations{};
	permutationHelper(0, array, permutations);
	return permutations;
}

void permutationHelper(int i, vector<int> &array, vector<vector<int>> &permutations) 
{
	if(i == array.size() - 1){
		permutations.push_back(array);
	}
	for(int j=i; j<array.size(); j++){
		swap(array[i], array[j]);
		permutationHelper(i+1, array, permutations);
		swap(array[i], array[j]);
	}
}
