#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

/*
Write a function that takes in a non-empty string and that returns a boolean representing whether the string is a palindrome.

A palindrome is defined as a string that's written the same forward and backward. Note that single-character strings are palindromes.

Sample Input
string = "abcdcba"
Sample Output
true
*/


using namespace std;
bool isPalindrome(string str) {
    string sen = str;
    reverse(str.begin(), str.end());
    if (sen.compare(str) == 0) return true;
    else return false;
}

int main()
{
  //Write code here
  return 0;
}
