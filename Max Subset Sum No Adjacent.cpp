#include <vector>

/*
Write a function that takes in an array of positive integers and returns the maximum sum of non-adjacent elements in the array.

If a sum can't be generated, the function should return 0.

Sample Input
array = [75, 105, 120, 75, 90, 135]
Sample Output
330 // 75 + 120 + 135
*/


using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
	if(array.size() == 0) return 0;
  int noAdjMax = array[0];

  for(int i = 2; i < array.size(); i++){
	  array[i] += noAdjMax;
	  noAdjMax = max(array[i-1], noAdjMax);
  }

  return *max_element(array.begin(), array.end());
}
