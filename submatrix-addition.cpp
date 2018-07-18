/*
Given a matrix of size n x m. You are given a series of submatrix inside the matrix. Find the sum of all elements inside that submatrix. Submatrix position are given in terms of its: top_left_cell and bottom_right_cell.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n and m,n is the number of rows and m is the number of columns.
The second line of each test case contains C[n][m]. 

The third line contains four value of x1, y1, x2, y2.

x1, y1 is the top left cell and x2, y2 is the bottom right cell.


Output:

Print the sum of all elements inside that submatrix.

Constraints:

1 ≤ T ≤ 15
1 ≤ n,m ≤ 10
1 ≤ C[n][m] ≤ 1000

Example:

Input:
2
5 6
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
3 4 4 5
3 3
9 8 7 4 2 1 6 5 3
1 2 3 3

Output:
78
26
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t, n, m, x1, x2, y1, y2;
	cin >> t;
	while (t > 0)   {
	    cin >> n >> m;
	    vector<vector<int> > vec(n); 
 
        for (int i = 0; i < n; i++) {
            vec[i] = vector<int>(m);
            for (int j = 0; j < m; j++)
                cin >> vec[i][j];
        }
        
        cin >> x1 >> y1 >> x2 >> y2;
        int r = 0;
        for (int i = x1-1; i < x2; i++) {
            for (int j = y1-1; j < y2; j++) {
                r += vec[i][j];
            }
            
        }
        
        cout << r << endl;
	    t--;
	}
	return 0;
}