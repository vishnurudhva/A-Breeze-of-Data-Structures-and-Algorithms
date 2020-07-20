#include <vector>
#include <bits/stdc++.h>

/*
Write a function that takes in two non-empty arrays of integers, finds the pair of numbers (one from each array) whose absolute difference is closest to zero, 
and returns an array containing these two numbers, with the number from the first array in the first position.

You can assume that there will only be one pair of numbers with the smallest difference.

Sample Input
arrayOne = [-1, 5, 10, 20, 28, 3]
arrayTwo = [26, 134, 135, 15, 17]
Sample Output
[28, 26]
*/

using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	vector<int> res{0, 0};
	int n = 0;
	int m = 0;
	int min = max(*max_element(arrayOne.begin(), arrayOne.end()), *max_element(arrayTwo.begin(), arrayTwo.end()));
	while(n<arrayOne.size() && m<arrayTwo.size())
	{
		if(arrayOne[n]-arrayTwo[m] == 0)
		{
			res[0]=arrayOne[n];
			res[1]=arrayTwo[m];
			break;
		}else if(arrayOne[n]-arrayTwo[m] > 0)
		{
			if(arrayOne[n]-arrayTwo[m] < min){
				min=arrayOne[n]-arrayTwo[m];
				res[0]=arrayOne[n];
				res[1]=arrayTwo[m];
			}
			m++;
		}else{
			if(arrayTwo[m]-arrayOne[n] < min){
				min=arrayTwo[m]-arrayOne[n];
				res[0]=arrayOne[n];
				res[1]=arrayTwo[m];
			}
			n++;
		}
	}
  return res;
}

int main()
{
  //Write your code here
  return 0;
}
