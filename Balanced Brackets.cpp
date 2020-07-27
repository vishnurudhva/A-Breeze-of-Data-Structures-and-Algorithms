#include<stack>

/*
Write a function that takes in a string made up of brackets ((, [, {, ), ], and }) and other optional characters. The function should return a boolean representing whether the string is balanced with regards to brackets.

A string is said to be balanced if it has as many opening brackets of a certain type as it has closing brackets of that type and if no bracket is unmatched. Note that an opening bracket can't match a corresponding closing bracket that comes before it, and similarly, a closing bracket can't match a corresponding opening bracket that comes after it. Also, brackets can't overlap each other as in [(]).

Sample Input
string = "([])(){}(())()()"
Sample Output
true // it's balanced
*/

using namespace std;

bool balancedBrackets(string str) {
  stack<char> s;
	
	for(int i=0; i < str.length(); i++){
		if(s.empty() == true){
			s.push(str[i]);
			continue;
		}
		if(str[i] == '}' && s.top() == '{') 
			s.pop();
		else if(str[i] == '}' && (s.top() == '(' || s.top() == '['))
			break;
			
		if(str[i] == ']' && s.top() == '[') 
			s.pop();
		else if(str[i] == ']' && (s.top() == '(' || s.top() == '{'))
			break;
			
		if(str[i] == ')' && s.top() == '(') 
			s.pop();
		else if(str[i] == ')' && (s.top() == '{' || s.top() == '['))
			break;
			
		if(str[i] == '{' || str[i] == '[' || str[i] == '(') 
			s.push(str[i]);
	}
  return s.empty();
}
