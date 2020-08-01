#include <vector>

/*
Write a function that takes in an n x m two-dimensional array (that can be square-shaped when n == m) and returns a one-dimensional array of all the array's elements in zigzag order.

Zigzag order starts at the top left corner of the two-dimensional array, goes down by one element, and proceeds in a zigzag pattern all the way to the bottom right corner.

Sample Input
array = [
  [1,  3,  4, 10],
  [2,  5,  9, 11],
  [6,  8, 12, 15],
  [7, 13, 14, 16],
]
Sample Output
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
*/

using namespace std;

vector<int> zigzagTraverse(vector<vector<int>> array) {
  vector<int> result{};
	int i = 0, j = 0, row = array.size(), col = array[0].size(), flag = 1;
	
	for(int x = 0; x < row; x++)
	{
		for(int y = 0; y < col; y++){
			if(flag == 0){
				result.push_back(array[i][j]);
				if(i - 1 < 0 || j + 1 > col - 1){
					flag = 1;
					if(j + 1 > col - 1) i++;
					else j++;
					continue;
				}
				i--;
				j++;
			}else{
				result.push_back(array[i][j]);
				if(i + 1 > row - 1 || j - 1 < 0){
					flag = 0;
					if(i + 1 > row - 1) j++;
					else i++;
					continue;
				}
				i++;
				j--;
			}
		}
	}
	
  return result;
}
