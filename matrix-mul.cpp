/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test case follows. The first line of each test case contains an integer N, denoting the number of elements in the array.
Then next line contains N space separated integers denoting the values of the element in the array.

Output:
For each test case the print the minimum number of operations needed to multiply the chain.

Constraints:
1<=T<=100
2<=N<=100
1<=A[]<=500

Example:
Input:
2
5
1 2 3 4 5
3
3 3 3
Output:
38
27
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int mmul (vector<int> a)    {
    int n = a.size();
    vector<vector <int>> m(n, vector<int> (n, -1));
    
    for (int i=1; i<n; i++)   {
        m[i][i] = 0;
    }
    
    /*for (int i=1; i<n; i++)   {
        for (int j=1; j<n; j++)   {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }*/
    
    for (int L=2; L<n; L++) {
        for (int i=0; i<n-L+1; i++) {
            int j = i+L-1;
            m[i][j] = INT_MAX;
            for (int k=i; k<j; k++) {
                int q = m[i][k] + m[k+1][j] + a[i-1]*a[k]*a[j];
				if (q < m[i][j])
					m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}

int main()
 {
	int t, n;
	cin >> t;
	while (t > 0)   {
	    cin >> n;
	    vector<int> a(n);
	    for (int i=0; i<n; i++) 
	        cin >> a[i];
	   
	    cout << mmul(a) << endl;
	    t--;
	}
	return 0;
}