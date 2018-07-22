/*
Find the first non-repeating element in a given array of integers.

Note: Array consists of only positive and negative integers and not zero.

Input:

The first line of input is an integer T, denoting the number of test cases. Each test case has subsequent two lines of input. First line is an integer N, denoting size of integer array A. Second line consists of N space separated integers of the array A.

Output:

The only line of output for each test case is the first non-repeating element in the array A. If there is no such element, print 0 as the output.

Constraints:

1<=T<=100;
1<=N<=100;
A[i] belongs to [-100,100]-{0}, where i is an integer denoting index of array.

Example:

Input:

4
5
-1 2 -1 3 2
6
9 4 9 6 7 4
3
1 1 1
2
-3 2


Output:

3
6
0
-3
*/
#include<iostream>
#include<vector>

using namespace std;
int main()
 {
	int t, n;
	cin >> t;
	vector<int> c(201, 0);
	while (t > 0)   {
	    cin >> n;
	    vector<int> a(n);
	    for (int i=0; i<n; i++)     {
	        cin >> a[i];
	        c[a[i]+100] += 1;
	    }
	    
	    int flg = 0;
	    for (int i=0; i<n; i++)    {
	        if (c[a[i]+100] == 1)   {
	            flg = 1;
	            cout << a[i] << endl;
	            break;
	        }
	    }
	    if (flg == 0)   
	        cout << "0" << endl;

	    std::fill(c.begin(), c.end(), 0);
	    t--;
	}
	return 0;
}