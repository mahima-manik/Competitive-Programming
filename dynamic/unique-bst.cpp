/*
Given an integer N, how many structurally unique binary search trees are there that store values 1...N?
*/

#include<bits/stdc++.h>
using namespace std;
int fact (int n)    {
    int ans = 1;
    for (int i=1; i<=n; i++)    {
        ans *= i;
    }
    return ans;
}
int main()
 {
	int t, n;
	cin >> t;
	while (t > 0)   {
	    cin >> n;
	    vector<int> dp(n+1, 0);
	    dp[0] = 1;
	    dp[1] = 1;
	    for (int i=2; i<=n; i++) {
	        for (int j=0; j<i; j++) {
	            dp[i] += dp[j] * dp[i-j-1];
	        }
	    }
	    cout << dp[n] << endl;
	    t--;
	}
	return 0;
}