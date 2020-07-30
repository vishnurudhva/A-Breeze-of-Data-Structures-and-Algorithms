using namespace std;

/*
Write a function that takes in two strings and returns the minimum number of edit operations that need to be performed on the first string to obtain the second string.

There are three edit operations: insertion of a character, deletion of a character, and substitution of a character for another.

Sample Input
str1 = "abc"
str2 = "yabd"
Sample Output
2 // insert "y"; substitute "c" for "d"
*/

int levenshteinDistanceHelper(string str1, string str2);

int levenshteinDistance(string str1, string str2) {
	if(str1.length() > str2.length())
  		return levenshteinDistanceHelper(str1, str2);
	else
		return levenshteinDistanceHelper(str2, str1);
}

int levenshteinDistanceHelper(string str1, string str2){
	vector<int> DP(str2.length()+1);
	for(int i = 0; i < DP.size(); i++) 
		DP[i] = i;
	int prev, j;
	for(int i = 1; i <= str1.size(); i++){
		prev = i;
		for(j = 1; j <= str2.size(); j++){
			if(str1[i - 1] == str2[j - 1])
			{
				int temp = DP[j-1];
				DP[j-1] = prev;
				prev = temp;
			}
			else{
				int temp = 1 + min(min(DP[j], DP[j-1]), prev);
				DP[j-1] = prev;
				prev = temp;
			}
		}
		DP[j-1] = prev;
	}
	return DP[str2.length()];
}
