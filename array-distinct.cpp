/*
Credits: https://practice.geeksforgeeks.org/problems/sum-of-distinct-elements/0
Find the sum of all non- repeated elements in an array.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, N is the size of array.
The second line of each test case contains N input C[i].

Output:

Print the sum of all non-repeated elements.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500
0 ≤ C[i] ≤ 1000

Example:

Input:
3
5
1 2 3 4 5
5
5 5 5 5 5
4
22 33 22 33

Output:
15
5
55
*/
#include<iostream>
#include <algorithm>

using namespace std;
int main()
{
	int t, n;
	cin >> t;
	while (t > 0)   {
	    cin >> n;
	    int a[n];
	    vector<int> d;
	    for (int i=0; i<n; i++) {
	        cin >> a[i];
	        if (!(find(d.begin(), d.end(), a[i]) != d.end()))
	            d.push_back(a[i]);
	    }
	    int r = 0;
	    for (int i=0; i<d.size(); i++)    {
	        r += d[i];
	    }
	    cout << r << endl;
	    t--;
	}
	return 0;
}