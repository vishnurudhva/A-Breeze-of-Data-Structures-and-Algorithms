#include <vector>

/*
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. The function should find all quadruplets in the array that sum up to the target sum and return a two-dimensional array of all these quadruplets in no particular order.

If no four numbers sum up to the target sum, the function should return an empty array.

Sample Input
array = [7, 6, 4, -1, 1, 2]
targetSum = 16
Sample Output
[[7, 6, 4, -1], [7, 6, 1, 2]] // the quadruplets could be ordered differently
*/


using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
	unordered_map<int, vector<vector<int>>> fourMap;
	vector<vector<int>> result{};
	for(int i = 0; i < array.size() - 1; i++){
		for(int j = i+1; j < array.size(); j++){
			if(fourMap.find(targetSum - (array[i] + array[j])) != fourMap.end()){
				for(int g = 0; g < fourMap[targetSum - (array[i] + array[j])].size(); g++){
					vector<int> temp = fourMap[targetSum - (array[i] + array[j])][g];
					temp.push_back(array[i]);
					temp.push_back(array[j]);
					result.push_back(temp);
				}
			}
		}
		for(int k = 0; k < i; k++){
			if(fourMap.find(array[k] + array[i]) != fourMap.end()){
				fourMap[array[k] + array[i]].push_back({array[k], array[i]});
			}else{
				fourMap[array[k] + array[i]] = vector<vector<int>>{{array[k], array[i]}};
			}
		}
	}
	return result;
}
