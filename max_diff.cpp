/*
Given an array C[] of integers, find out the maximum difference between any two elements such that larger element appears after the smaller number in C[].
Examples: If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 8 (Diff between 10 and 2). If array is [ 7, 9, 5, 6, 3, 2 ] then returned value should be 2 (Diff between 7 and 9).

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input C[i].

Output:

Print the maximum difference between two element. Otherwise print -1

Constraints:

1 ≤ T ≤ 80
2 ≤ N ≤ 100
1 ≤ C[i] ≤ 500

Example:

Input:
2
7
2 3 10 6 4 8 1
5
1 2 90 10 110

Output:
8
109
*/
#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int t, n;
	cin >> t;
	while (t > 0)   {
	    cin >> n;
	    vector<int> a(n);
	    int mdif = -1;
	    for (int i=0; i<n; i++) {
	        cin >> a[i];
	    }
	    for (int i=0; i<n-1; i++)   {
	        int m = i+1;
	        for (int j=i+2; j<n; j++)   {   //find max
	            if (a[j] > a[m] && a[j] > a[i])
	                m = j;
	        }
	        if ((a[m] - a[i]) > mdif)
	            mdif = a[m] - a[i];
	    }
	    cout << mdif << endl;
	    t--;
	}
	return 0;
}