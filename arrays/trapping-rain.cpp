/*
Given n non-negative integers in array representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example:
Input:
3
2 0 2
Output:
2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains an integer N followed by N numbers to be stored in array.

Output:
Print trap units of water in the middle gap.

Constraints:
1<=T<=100
3<=N<=100
0<=Arr[i]<10

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
 0
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, n;
	cin >> t;
	while (t > 0)   {
	    cin >> n;
	    vector<int> a(n);
	    for (int i=0; i<n; i++)    {
	        cin >> a[i];
	    }
	    
	    vector<int> lar_left(n);
	    lar_left[0] = a[0];
	    for (int i=1; i<n; i++)    {
	        lar_left[i] = max(lar_left[i-1], a[i]);
	    }
	    
	    vector<int> lar_right(n);
	    lar_right[n-1] = a[n-1];
	    for (int i=n-2; i>=0; i--)  {
	        lar_right[i] = max(lar_right[i+1], a[i]);
	    }
	    
	    int water = 0;
	    for (int i=0; i<n; i++) {
	        if (min(lar_left[i], lar_right[i]) >= a[i])
	            water += min(lar_left[i], lar_right[i]) - a[i];
	    }
	    
	    cout << water << endl;
	    t--;
	}
	return 0;
}