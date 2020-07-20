#include <vector>
#include <bits/stdc++.h>

/*
You're given an array of integers and an integer. Write a function that moves all instances of that integer in the array to the end of the array and returns the array.

The function should perform this in place (i.e., it should mutate the input array) and doesn't need to maintain the order of the other integers.

Sample Input
array = [2, 1, 2, 2, 2, 3, 4, 2]
toMove = 2
Sample Output
[1, 3, 4, 2, 2, 2, 2, 2] // the numbers 1, 3, and 4 could be ordered differently
*/

using namespace std;
vector<int> moveElementToEnd(vector<int> array, int toMove) {
  int n = array.size()-1, i=0;
	while(i<n){
		while(array[n] == toMove && i<n) n--;
		if(array[i] == toMove)
		{
			array[i] = array[n];
			array[n] = toMove;
		}
    i++;
	}
  return array;
}

int main()
{
  //Write your code here
  return 0;
}
