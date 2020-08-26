#include <vector>
using namespace std;

/*
Write a function that takes in a non-empty array of integers and returns the greatest sum that can be generated from a strictly-increasing subsequence in the array as well as an array of the numbers in that subsequence.

A subsequence of an array is a set of numbers that aren't necessarily adjacent in the array but that are in the same order as they appear in the array. For instance, the numbers [1, 3, 4] form a subsequence of the array [1, 2, 3, 4], and so do the numbers [2, 4]. Note that a single number in an array and the array itself are both valid subsequences of the array.

You can assume that there will only be one increasing subsequence with the greatest sum.

Sample Input
array = [10, 70, 20, 30, 50, 11, 30]
Sample Output
[110, [10, 20, 30, 50]] // The subsequence [10, 20, 30, 50] is strictly increasing and yields the greatest sum: 110.
*/

vector<int> getMaxVector(vector<int> array, vector<int> seq, int ind){
	vector<int> ans;
	while(ind != INT_MIN ){
		ans.push_back(array[ind]);
		ind = seq[ind];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
	int n = array.size(), ind = -1;
  vector<int> DP = array;
	vector<int> seq(n, INT_MIN);
	for(int i = 0; i < n; i++){
		int hold = INT_MIN;
		for(int j = 0; j < i; j++){
			if(array[j] < array[i] && DP[j] + array[i] >= DP[i]){
				DP[i] = DP[j] + array[i];
				seq[i] = j;
			}		
		}
	}
	for(int num : DP) cout << num << " " ;
	int mx = INT_MIN;
	for(int i = 0; i < n; i++){
		if(DP[i] > mx){
			mx = DP[i];
			ind = i;
		}
	}

  return {{mx}, getMaxVector(array, seq, ind)};
}
