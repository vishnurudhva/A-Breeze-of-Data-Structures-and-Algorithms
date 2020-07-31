using namespace std;

/*
Write a function that, given a string, returns its longest palindromic substring.

A palindrome is defined as a string that's written the same forward and backward. Note that single-character strings are palindromes.

You can assume that there will only be one longest palindromic substring.

Sample Input
string = "abaxyzzyxf"
Sample Output
"xyzzyx"
*/

string getString(string str, int i, int j){
	string s = "";
	for(int x = i; x <= j; x++){
		s += str[x];
	}
	return s;
}

string longestPalindromicSubstring(string str) {
	string longest = "";
	if(str.length() == 2 && str[0] != str[1]) 
	{
		longest += str[0];
		return longest;
	}
	int x, y;
  	for(int i = 1; i < str.length(); i++){
		if(str[i] == str[i-1]){
			x = i-2;
			y = i+1;
			while(x >= 0 && y < str.length() && str[x] == str[y]){
				x--;
				y++;
			}
			string temp = getString(str, x+1, y-1);
			if(temp.length() > longest.length()){
				longest = temp;
			}
		}
		if(i != str.length()-1 && str[i-1] == str[i+1]){
			x = i-2;
			y = i+2;
			while(x >= 0 && y < str.length() && str[x] == str[y]){
				x--;
				y++;
			}
			string temp = getString(str, x+1, y-1);
			if(temp.length() > longest.length()){
				longest = temp;
			}
		}
		else{
			continue;
		}
  	}
  	return str.length() > 1 ? longest : str;
}
