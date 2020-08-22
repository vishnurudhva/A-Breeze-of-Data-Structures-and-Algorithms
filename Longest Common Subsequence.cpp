#include <vector>
using namespace std;

/*
Write a function that takes in two strings and returns their longest common subsequence.

A subsequence of a string is a set of characters that aren't necessarily adjacent in the string but that are in the same order as they appear in the string. For instance, the characters ["a", "c", "d"] form a subsequence of the string "abcd", and so do the characters ["b", "d"]. Note that a single character in a string and the string itself are both valid subsequences of the string.

You can assume that there will only be one longest common subsequence.

Sample Input
str1 = "ZXVVYZW"
str2 = "XKYKZPW"
Sample Output
["X", "Y", "Z", "W"]
*/

vector<char> longestCommonSubsequence(string str1, string str2) {		
  vector<vector<int>> DP(str2.size() + 1, vector<int>(str1.size() + 1, 0));
	
	for(int i = 1; i < str2.size() + 1; i++)
	{
		for(int j = 1; j < str1.size() + 1; j++)
		{
			if(str1[j - 1] == str2[i - 1])
				DP[i][j] = 1 + DP[i - 1][j - 1];
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}
	
	vector<char> ans(DP[str2.size()][str1.size()]);
	int x = str2.size(), y = str1.size(), k = ans.size() - 1;
	while(x > 0 && y > 0)
	{
		if(DP[x][y] == max(DP[x - 1][y], DP[x][y - 1])){
			if(DP[x - 1][y] > DP[x][y - 1])
			{
				x--;
			}else{
				y--;
			}
		}
		else{
			ans[k] = str1[y - 1];
			x--;
			y--;
			k--;
		}
	}	
  return ans;
}
