using namespace std;
/*
Write a function that takes in an array of integers and returns the length of the longest peak in the array.

A peak is defined as adjacent integers in the array that are strictly increasing until they reach a tip (the highest value in the peak), at which point they become strictly decreasing. At least three integers are required to form a peak.

For example, the integers 1, 4, 10, 2 form a peak, but the integers 4, 0, 10 don't and neither do the integers 1, 2, 2, 0. Similarly, the integers 1, 2, 3 don't form a peak because there aren't any strictly decreasing integers after the 3.

Sample Input
array = [1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3]
Sample Output
6 // 0, 10, 6, 5, -1, -3
*/
int longestPeak(vector<int> array) {
	int i = 1, maxPeak = 0;
	while(i < int(array.size()-1))
	{
		if(!(array[i-1] < array[i] && array[i] > array[i+1])){
			i++;
			continue;
		}
		int leftPTR = i-2;
		while(leftPTR >= 0 && array[leftPTR] < array[leftPTR+1]) 
			 --leftPTR;
		
		int rightPTR = i+2;
		while(rightPTR < array.size() && array[rightPTR] < array[rightPTR-1]) 
			 ++rightPTR;
		maxPeak = max(maxPeak, rightPTR - leftPTR - 1);
		i = rightPTR;		
	}
	return maxPeak;
}

int main()
{
  //Write your code here
  return 0;
}
