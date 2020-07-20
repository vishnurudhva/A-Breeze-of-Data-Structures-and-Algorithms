#include <vector>
#include <bits/stdc++.h>

/*
Write a function that takes in an array of integers and returns a sorted version of that array. Use the Insertion Sort algorithm to sort the array.

If you're unfamiliar with Insertion Sort, we recommend watching the Conceptual Overview section of this question's video explanation before starting to code.

Sample Input
array = [8, 5, 2, 9, 5, 6, 3]
Sample Output
[2, 3, 5, 5, 6, 8, 9]
*/

using namespace std;

vector<int> insertionSort(vector<int> array) {
	int x, j;
  for(int i=1; i<array.size(); i++){
		j = i;
		while(array[j-1]>array[j] && j-1 >= 0)
		{
      int temp = array[j-1];
			array[j-1] = array[j];
      array[j] = temp;
			j--;
		}
	}
  return array;
}

int main()
{
 //Write your code here
 return 0;
}
