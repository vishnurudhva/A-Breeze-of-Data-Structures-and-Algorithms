#include <vector>
#include <algorithm>
using namespace std;
 
/*
You're given an array of arrays where each subarray holds two integer values and represents an item; the first integer is the item's value, and the second integer is the item's weight. You're also given an integer representing the maximum capacity of a knapsack that you have.

Your goal is to fit items in your knapsack without having the sum of their weights exceed the knapsack's capacity, all the while maximizing their combined value. Note that you only have one of each item at your disposal.

Write a function that returns the maximized combined value of the items that you should pick as well as an array of the indices of each item picked.

If there are multiple combinations of items that maximize the total value in the knapsack, your function can return any of them.

Sample Input
items = [[1, 2], [4, 3], [5, 6], [6, 7]]
capacity = 10
Sample Output
[10, [1, 3]] // items [4, 3] and [6, 7]
*/

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
  vector<vector<int>> DP(items.size() + 1, vector<int>(capacity + 1, 0));

	for(int i = 1; i < items.size() + 1; i++){
		for(int j = 0; j < capacity + 1; j++){
			if(j < items[i - 1][1]) DP[i][j] = DP[i - 1][j];
			else{
				DP[i][j] = max(items[i - 1][0] + DP[i - 1][j - items[i - 1][1]], DP[i - 1][j]);
			}
		}
	}
	vector<vector<int>> indices{{}, {}};
	indices[0].push_back(DP[items.size()][capacity]);
	int i = DP.size() - 1, j = DP[0].size() - 1;
	while(i > 0){
		if(DP[i][j] == DP[i - 1][j]) i--;
		else{
			indices[1].push_back(i - 1);
			j -= items[i - 1][1];
			i--;
		}
		if(j == 0) break;
	}
	
  return indices;
}
