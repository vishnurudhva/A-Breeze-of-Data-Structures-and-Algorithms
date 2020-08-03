#include <vector>
using namespace std;

/*
Write a function that takes in an array of at least two integers and that returns an array of the starting and ending indices of the smallest subarray in the input array that needs to be sorted in place in order for the entire input array to be sorted (in ascending order).

If the input array is already sorted, the function should return [-1, -1].

Sample Input
array = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]
Sample Output
[3, 9]
*/

vector<int> subarraySort(vector<int> array) {
	int min = INT_MAX, max = INT_MIN;
	vector<int> ans{};
	for(int i = 1; i < array.size() - 1; ++i)
	{
		if(array[i] >= array[i - 1] && array[i] <= array[i + 1]) continue;
		if(array[i] < min) min = array[i];
		if(array[i] > max) max = array[i];
	}
	if(min > array[array.size() - 1]) min = array[array.size() - 1];
	if(max < array[0]) max = array[0];

	for(int i = 0; i < array.size(); ++i)
	{
		if(array[i] <= min) continue;
		ans.push_back(i);
		break;
	}
	for(int i = array.size() - 1; i >= 0 ; --i)
	{
		if(array[i] >= max) continue;
		ans.push_back(i);
		break;
	}
	vector<int> cont = {-1, -1};
	return ans.size() == 0 ? cont : ans;
}
