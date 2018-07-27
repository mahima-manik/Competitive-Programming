/*
https://www.hackerrank.com/contests/srin-aadc03/challenges/classic-01-knapsack/
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int max(int a, int b)   {
    if (a >= b)
        return a;
    else
        return b;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int t, n, s;
    cin >> t;
    while (t > 0)   {
        // s - capacity, n - # of articles
        cin >> s >> n;
        vector <int> w(n);
        vector <int> v(n);
        for (int i=0; i<n; i++) {
            cin >> w[i] >> v[i];
        }
        //prints
        /*for (int i=0; i<n; i++) {
            cout << w[i] <<" ";
        }
        cout << endl;
        for (int i=0; i<n; i++) {
            cout << v[i] <<" ";
        }
        cout << endl;*/
        
        vector<vector <int>> d(n+1, vector<int>(s+1, 0));
        for (int i=0; i<s+1; i++)   {
            d[0][i] = 0;
        }
        for (int i=0; i<n+1; i++)   {
            d[i][0] = 0;
        }
        for (int i=1; i<n+1; i++)   {
            for (int j=1; j<s+1; j++)   {
                if (w[i-1] < j) {
                    d[i][j] = max(d[i-1][j], v[i-1]+d[i-1][j-w[i-1]]);
                }
                else{
                    d[i][j] = d[i-1][j];
                }
            }
        }
        cout << d[n][s] << endl;
        t--;
    }
    return 0;
}
