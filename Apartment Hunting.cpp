#include <vector>
#include <unordered_map>


/*
You're looking to move into a new apartment, and you're given a list of blocks where each block contains an apartment that you could move into. In order to pick your apartment, you want to optimize its location. You also have a list of requirements: a list of buildings that are important to you. For instance, you might value having a school and a gym near your apartment. The list of blocks that you have contains information at every block about all of the buildings that are present and absent at the block in question. For instance, for every block, you might know whether a school, a pool, an office, and a gym are present.

In order to optimize your life, you want to minimize the farthest distance you'd have to walk from your apartment to reach any of your required buildings.

Write a function that takes in a list of blocks and a list of your required buildings and that returns the location (the index) of the block that's most optimal for you.

If there are multiple most optimal blocks, your function can return the index of any one of them.

Sample Input
blocks = [
  {
    "gym": false,
    "school": true,
    "store": false,
  },
  {
    "gym": true,
    "school": false,
    "store": false,
  },
  {
    "gym": true,
    "school": true,
    "store": false,
  },
  {
    "gym": false,
    "school": true,
    "store": false,
  },
  {
    "gym": false,
    "school": true,
    "store": true,
  },
]
reqs = ["gym", "school", "store"]
Sample Output
3 // at index 3, the farthest you'd have to walk to reach a gym, a school, or a store is 1 block; at any other index, you'd have to walk farther
*/


using namespace std;

int maxCol(vector<vector<int>> reqMap, int j){
	int max = INT_MIN;
	for(int i = 0; i < reqMap.size(); i++)
	{
		if(reqMap[i][j] > max)
			max = reqMap[i][j];
	}
	return max;
}

int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {
	if(blocks.size() == 0) return -1;
	vector<vector<int>> reqMap(reqs.size(), vector<int>(blocks.size()));
	for(int i = 0; i < reqs.size(); i++)
	{
		int lastOccurence = -1;
		for(int j = 0; j < blocks.size(); j++)
		{
			if(blocks[j][reqs[i]] == true){
				lastOccurence = j;
				reqMap[i][j] = 0;
			}
			else if(lastOccurence == -1)
				reqMap[i][j] = INT_MAX;
			else
				reqMap[i][j] = j - lastOccurence;
		}
		for(int j = blocks.size() - 1; j >= 0; j--)
		{
			if(blocks[j][reqs[i]] == true){
				lastOccurence = j;
				reqMap[i][j] = 0;
			}
			else if(lastOccurence > j)
				reqMap[i][j] = min(reqMap[i][j], lastOccurence - j);
			else
				reqMap[i][j] = min(reqMap[i][j], j - lastOccurence);
		}
	}

	int minInd = 0, min = INT_MAX;
	for(int i = 0; i < reqMap[0].size(); i++){
		int hold = maxCol(reqMap, i);
		if(hold < min){
			min = hold;
			minInd = i;
		}
	}
	
	return minInd;
}
