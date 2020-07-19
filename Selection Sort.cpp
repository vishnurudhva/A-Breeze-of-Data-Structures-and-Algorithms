#include <vector>
#include <bits/stdc++.h>

/*
Write a function that takes in an array of integers and returns a sorted version of that array. Use the Selection Sort algorithm to sort the array.

If you're unfamiliar with Selection Sort, we recommend watching the Conceptual Overview section of this question's video explanation before starting to code.

Sample Input
array = [8, 5, 2, 9, 5, 6, 3]
Sample Output
[2, 3, 5, 5, 6, 8, 9]
*/


using namespace std;

vector<int> selectionSort(vector<int> array) {
  int x=0, mn;
	
	for(int i=0; i<array.size(); i++)
	{
		mn=x;
		for(int j=x; j<array.size(); j++)
		{
			if(array[j]<array[mn]) mn = j;
		}
		int temp = array[x];
		array[x] = array[mn];
		array[mn] = temp;
		x++;		
	}
  return array;
}

int main()
{
  //Write your code here
  return 0;
}
