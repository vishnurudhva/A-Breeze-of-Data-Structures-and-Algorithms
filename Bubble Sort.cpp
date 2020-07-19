#include <vector>
#include <bits/stdc++.h>

/*
Write a function that takes in an array of integers and returns a sorted version of that array. Use the Bubble Sort algorithm to sort the array.

If you're unfamiliar with Bubble Sort, we recommend watching the Conceptual Overview section of this question's video explanation before starting to code.

Sample Input
array = [8, 5, 2, 9, 5, 6, 3]
Sample Output
[2, 3, 5, 5, 6, 8, 9]
*/

using namespace std;

vector<int> bubbleSort(vector<int> array) {
  for(int i=0; i<array.size(); i++)
	{
		for(int j=i; j<array.size(); j++)
		{
			if(array[i]>array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
  return array;
}

int main()
{
  //Write your code here
  return 0;
}
