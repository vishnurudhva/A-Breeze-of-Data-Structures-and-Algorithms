#include <vector>

/*
Given an array of positive integers representing coin denominations and a single non-negative integer n representing a target amount of money, write a function that returns the smallest number of coins needed to make change for that target amount using the given coin denominations.

If it's impossible to make change for the target amount, return -1.

Note that an unlimited amount of coins is at your disposal.

Sample Input
n = 7
denoms = [1, 5, 10]
Sample Output
3 // 2x1 + 1x5
*/

using namespace std;
int minNumberOfCoinsForChange(int n, vector<int> denoms) {
	vector<int> DP(n+1, INT_MAX);
	DP[0] = 0;
  for(int d: denoms){
		for(int i=0; i<=n; i++){
			if(d > i) continue;
			int comp = DP[i-d];
			if(DP[i-d] != INT_MAX) comp++;
			DP[i] = min(DP[i], comp);
		}
	}
  return DP[n] != INT_MAX ? DP[n] : -1;
}
