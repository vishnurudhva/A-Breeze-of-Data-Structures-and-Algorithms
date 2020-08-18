#include <vector>
using namespace std;

/*
Write a function that takes in an array of integers and returns an array of length 2 representing the largest range of integers contained in that array.

The first number in the output array should be the first number in the range, while the second number should be the last number in the range.

A range of numbers is defined as a set of numbers that come right after each other in the set of real integers. For instance, the output array [2, 6] represents the range {2, 3, 4, 5, 6}, which is a range of length 5. Note that numbers don't need to be sorted or adjacent in the input array in order to form a range.

You can assume that there will only be one largest range.

Sample Input
array = [1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6]
Sample Output
[0, 7]
*/

vector<int> largestRange(vector<int> array) {
	unordered_map<int, bool> map;
	for(int ele : array)
		map[ele] = false;
	int left, right, count = 0;
	int actLeft = 0, actRight = 0;
	for(int i = 0; i < array.size(); i++)
	{
		if(map[array[i]] == true) continue;
		left = array[i] - 1;
		right = array[i] + 1;
		map[array[i]] = true;
		while(map.find(left) != map.end()) map[left--] = true;
		while(map.find(right) != map.end()) map[right++] = true;
		left++;
		right--;
		if(right - left > actRight - actLeft){
			actLeft = left;
			actRight = right;
		}
	}
  return {actLeft, actRight};
}
