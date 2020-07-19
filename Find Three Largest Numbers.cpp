#include <bits/stdc++.h>

/*
Write a function that takes in an array of at least three integers and, without sorting the input array, returns a sorted array of the three largest integers in the input array.
The function should return duplicate integers if necessary; for example, it should return [10, 10, 12] for an input array of [10, 5, 9, 10, 12].
Sample Input
array = [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]
Sample Output
[18, 141, 541]
*/

using namespace std;
vector<int> findThreeLargestNumbers(vector<int> array) {
    int mx, mn, pmx, ppmx, cmx=0, cpmx=0, cppmx=0;
    vector<int> d;
    mx=array[0];
    for(int i=0; i<array.size(); i++){
        if(array[i]>mx) mx = array[i];
    }
    for(int i=0; i<array.size(); i++){
        if(array[i]<mn) mn = array[i];
    }
    pmx=mn;
    ppmx=mn;
    for(int i=0; i<array.size(); i++){
        if(array[i]<mx && array[i]>pmx) pmx = array[i];
    }
    for(int i=0; i<array.size(); i++){
        if(array[i]<pmx && array[i]>ppmx) ppmx = array[i];
    }
    for(int i=0; i<array.size(); i++){
        if(array[i]==mx) cmx += 1;
        else if(array[i]==pmx) cpmx += 1;
        else if(array[i]==ppmx) cppmx += 1;
    }
    for(int i=0; i<cppmx; i++) d.push_back(ppmx);
    for(int i=0; i<cpmx; i++) d.push_back(pmx);
    for(int i=0; i<cmx; i++) d.push_back(mx);
    d = vector<int>(d.begin()+d.size()-3, d.end());
    return d;
}

int main()
{
  //Write code here
  return 0;
}
