#include <bits/stdc++.h>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  map<int, int> s;
  vector<int> p;

  for (int i=0; i<array.size(); i++)
  {
    if(s.find(array[i]) == s.end())
    {
      s[targetSum-array[i]] = array[i]; 
    }else{
      p.push_back(array[i]);
      p.push_back(targetSum-array[i]);
    }
  }
  return p;
}

int main(){
  // Write your code here
  return 0;
}
