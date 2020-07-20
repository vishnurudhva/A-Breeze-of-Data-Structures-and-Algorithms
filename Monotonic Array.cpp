#include <bits/stdc++.h>

/*
Write a function that takes in an array of integers and returns a boolean representing whether the array is monotonic.

An array is said to be monotonic if its elements, from left to right, are entirely non-increasing or entirely non-decreasing.

Sample Input
array = [-1, -5, -10, -1100, -1100, -1101, -1102, -9001]
Sample Output
true
*/

using namespace std;
bool isMonotonic(vector<int> array) {
	int v = 0;
	if(array.size() == 1 || array.size() == 0) return true;
  for(int i=0; i<array.size()-1; i++)
	{
		if(array[i]>array[i+1]){
			v=1;
			break;
		}
	}
	if(v == 0){
		for(int j=0; j<array.size()-1; j++)
		{
			if(array[j]>array[j+1]){
				return false;
			}
		}
	}else{
		for(int j=0; j<array.size()-1; j++)
		{
			if(array[j]<array[j+1]){
				return false;
			}
		}
	}
  return true;
}

int main()
{
  //Write your code here
  return 0;
}
