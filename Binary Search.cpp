#include <vector>
#include <bits/stdc++.h>

/*
Write a function that takes in a sorted array of integers as well as a target integer. The function should use the Binary Search algorithm to determine
if the target integer is contained in the array and should return its index if it is, otherwise -1.
If you're unfamiliar with Binary Search, we recommend watching the Conceptual Overview section of this question's video explanation before starting to code.

Sample Input
array = [0, 1, 21, 33, 45, 45, 61, 71, 72, 73]
target = 33
Sample Output
3
*/

using namespace std;

int binarySearch(vector<int> array, int target) {
  int i=0, j=array.size()-1;
  int mid=j/2;
  while (i<=j)
  {
    if(array[mid]==target)
    {
      return mid;
    }
    else if(array[mid]>target)
    {
      j = mid-1;
      mid = (i+j)/2;
    }
    else
    {
      i = mid+1;
      mid = (i+j)/2;
    }
  }
  return -1;
}

int main()
{
  //Write your code here
  return 0;
}
