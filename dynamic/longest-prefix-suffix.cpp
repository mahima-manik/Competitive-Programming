/*
Given a string of character, find the length of longest proper prefix which is also a proper suffix.
Example:
S = abab
lps is 2 because, ab.. is prefix and ..ab is also a suffix.

Input:
First line is T number of test cases. 1<=T<=100.
Each test case has one line denoting the string of length less than 100000.

Expected time compexity is O(N).

Output:
Print length of longest proper prefix which is also a proper suffix.

Example:
Input:
2
abab
aaaa

Output:
2
3
*/
#include<vector>
#include<iostream>
using namespace std;
int main()
 {
	int t, n;
	string str;
	cin >> t;
	while (t > 0)   {
	    cin >> str;
	    n = str.size();
		//dp[i] is defined as length of longest prefix which is also a suffix for the substring 0..i
	    vector<int> dp(n, 0);
	    for (int i=1; i<n; i++) {
	        if (str[dp[i-1]] == str[i])
	            dp[i] = dp[i-1]+1;
            else if (str[0]==str[i])
                dp[i] = 1;
	    }
		for (int i=0; i<n-1; i++) {
	        cout << dp[i] << " ";
	    }
	    cout << dp[n-1] << endl;
	    t--;
	}
	return 0;
}