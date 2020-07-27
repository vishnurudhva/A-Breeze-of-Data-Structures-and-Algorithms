#include <vector>

/*
Given an array of distinct positive integers representing coin denominations and a single non-negative integer n representing a target amount of money, write a function that returns the number of ways to make change for that target amount using the given coin denominations.

Note that an unlimited amount of coins is at your disposal.

Sample Input
n = 6
denoms = [1, 5]
Sample Output
2 // 1x1 + 1x5 and 6x1
*/


using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  vector<int> DP(n+1, 0);
	DP[0] = 1;
  for(int d: denoms){
		for(int i=0; i<=n; i++){
			if(d > i) continue;
			DP[i] += DP[i-d];
		}
	}
  return DP[n];
}
