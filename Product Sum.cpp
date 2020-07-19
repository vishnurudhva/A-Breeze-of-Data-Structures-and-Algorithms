#include <bits/stdc++.h>
#include <any>
#include <vector>

/*
Write a function that takes in a "special" array and returns its product sum.

A "special" array is a non-empty array that contains either integers or other "special" arrays. The product sum of a "special" array is the sum of its elements, where "special" arrays inside it are summed themselves and then multiplied by their level of depth.

The depth of a "special" array is how far nested it is. For instance, the depth of [] is 1; the depth of the inner array in [[]] is 2; the depth of the innermost array in [[[]]] is 3.

Therefore, the product sum of [x, y] is x + y; the product sum of [x, [y, z]] is x + 2y + 2z; the product sum of [x, [y, [z]]] is x + 2y + 6z.

Sample Input
array = [5, 2, [7, -1], 3, [6, [-13, 8], 4]]
Sample Output
12 // calculated as: 5 + 2 + 2 * (7 - 1) + 3 + 2 * (6 + 3 * (-13 + 8) + 4)
*/

using namespace std;
int productSum(vector<any> array, int multiplier=1) {
	int k=0;
	for(auto el : array)
	{
		if(el.type() != typeid(vector<any>)){
			k+=(multiplier*(any_cast<int>(el)));
		}else{
			k+=(multiplier*(any_cast<int>(productSum(any_cast<vector<any>>(el), multiplier+1))));
		}
	}
  return k;
}

int main()
{
  //Write your code here
  return 0;
}
