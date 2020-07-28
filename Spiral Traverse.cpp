#include<vector>

/*
Write a function that takes in an n x m two-dimensional array (that can be square-shaped when n == m) and returns a one-dimensional array of all the array's elements in spiral order.

Spiral order starts at the top left corner of the two-dimensional array, goes to the right, and proceeds in a spiral pattern all the way until every element has been visited.

Sample Input
array = [
  [1,   2,  3, 4],
  [12, 13, 14, 5],
  [11, 16, 15, 6],
  [10,  9,  8, 7],
]
Sample Output
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
*/

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
  int startRow = 0, startCol = 0;
  int endRow = array.size()-1, endCol = array[0].size()-1;
  vector<int> spiral;
  while(startRow <= endRow && startCol <= endCol)
  {
	  for(int i = startCol; i <= endCol; i++){
		  spiral.push_back(array[startRow][i]);
	  }

	  for(int i = startRow+1; i <= endRow; i++){
		  spiral.push_back(array[i][endCol]);
	  }

	  for(int i = endCol-1; i >= startCol; i--){
		  if(startRow == endRow) break;
		  spiral.push_back(array[endRow][i]);
	  }

	  for(int i = endRow-1; i > startRow; i--){
			if(startCol == endCol) break;
		  spiral.push_back(array[i][startCol]);
	  }
	  startRow++;
	  startCol++;
	  endRow--;
	  endCol--;
  }

  return spiral;
}
