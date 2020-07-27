#include <vector>

/*
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. The function should find all triplets in the array that sum up to the target sum and return a two-dimensional array of all these triplets. The numbers in each triplet should be ordered in ascending order, and the triplets themselves should be ordered in ascending order with respect to the numbers they hold.

If no three numbers sum up to the target sum, the function should return an empty array.

Sample Input
array = [12, 3, 1, 2, -6, 5, -8, 6]
targetSum = 0
Sample Output
[[-8, 2, 6], [-8, 3, 5], [-6, 1, 5]]
*/


using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  sort(array.begin(), array.end());
	vector<vector<int>> result;
	for(int i=0; i<array.size(); i++){
		int left = i+1;
		int right = array.size()-1;
		while(left < right){
			int temp = array[i] + array[left] + array[right];
			if(temp == targetSum){
				result.push_back(vector<int>({array[i], array[left], array[right]}));
				left++;
				right--;
			}
			else if(temp > targetSum){
				right--;
			}
			else{
				left++;
			}
		}
	}
  return result;
}

int main()
{
  //Write your code here
  return 0;
}
