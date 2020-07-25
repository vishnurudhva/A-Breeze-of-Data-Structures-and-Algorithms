#include <vector>

/*
You're given a two-dimensional array (a matrix) of potentially unequal height and width containing only 0s and 1s. Each 0 represents land, and each 1 represents part of a river. A river consists of any number of 1s that are either horizontally or vertically adjacent (but not diagonally adjacent). The number of adjacent 1s forming a river determine its size.

Note that a river can twist. In other words, it doesn't have to be a straight vertical line or a straight horizontal line; it can be L-shaped, for example.

Write a function that returns an array of the sizes of all rivers represented in the input matrix. The sizes don't need to be in any particular order.

Sample Input
matrix = [
  [1, 0, 0, 1, 0],
  [1, 0, 1, 0, 0],
  [0, 0, 1, 0, 1],
  [1, 0, 1, 0, 1],
  [1, 0, 1, 1, 0],
]
Sample Output
[1, 2, 2, 2, 5] // The numbers could be ordered differently.

// The rivers can be clearly seen here:
// [
//   [1,  ,  , 1,  ],
//   [1,  , 1,  ,  ],
//   [ ,  , 1,  , 1],
//   [1,  , 1,  , 1],
//   [1,  , 1, 1,  ],
// ]
*/

using namespace std;
int riverCount(vector<vector<int>> &matrix, int i, int j, int n, int m){
	if(matrix[i][j] == 0) return 0;
	matrix[i][j] = 0;
	int count = 0;
	if(i-1 >= 0) count += riverCount(matrix, i-1, j, n, m);
	if(i+1 < n) count += riverCount(matrix, i+1, j, n, m);
	if(j-1 >= 0) count += riverCount(matrix, i, j-1, n, m);
	if(j+1 < m) count += riverCount(matrix, i, j+1, n, m);
	return 1 + count;
}
vector<int> riverSizes(vector<vector<int>> matrix) {
  vector<int> array;
	int n = matrix.size(), m = matrix[0].size();
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++){
			if(matrix[i][j] == 1){
				array.push_back(riverCount(matrix, i, j, n, m));
			}
		}
	}
  sort(array.begin(), array.end());
  return array;
}

int main()
{
  //Write your code here
  return 0;
}
