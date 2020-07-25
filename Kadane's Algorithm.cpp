#include <vector>
/*
Write a function that takes in a non-empty array of integers and returns the maximum sum that can be obtained by summing up all of the integers in a non-empty subarray of the input array. A subarray must only contain adjacent numbers.

Sample Input
array = [3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4]
Sample Output
19 // [1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1]
*/
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  int maxEndingHere = array[0], maxSoFar = array[0];
	for(int i=1; i<array.size(); i++){
		maxEndingHere = max(array[i], array[i]+maxEndingHere);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}
  return maxSoFar;
}

int main()
{
  //Write your code here
  return 0;
}
