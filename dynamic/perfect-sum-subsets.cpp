/*
Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an nteger n denoting the size of the array. The next line contains n space separated integers forming the array. The last line contains the sum.

Output:
Count all the subsets of given array with sum equal to given sum.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=sum<=10^5

Example:
Input:
2
6
2 3 5 6 8 10
10
5
1 2 3 4 5
10

Output:
3
3
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> my_ans;

void print_subs(vector<vector<int> > dp, vector<int> a, int x, int n, vector<int> ans)   {
    if (dp[x][n]>0) {
        if (a[n-1]==x) {
            vector<int> ans_copy(ans.begin(), ans.end());
            print_subs(dp, a, x, n-1, ans_copy);
            ans.push_back(a[n-1]);
            
            my_ans.push_back(ans);
            // for (int i=0; i<ans.size(); i++)    {
            //     cout << ans[i] << " ";
            // }
            // cout << endl;
            return;
        }
        else if (a[n-1]>x)  {
            print_subs(dp, a, x, n-1, ans);
            return;
        }
        else if (a[n-1]<x)  {
            vector<int> ans_copy1(ans.begin(), ans.end());
            vector<int> ans_copy2(ans.begin(), ans.end());
            print_subs(dp, a, x, n-1, ans_copy1);
            if (dp[x-a[n-1]][n-1]>0)    {
                //cout << "here" << a[n-1] << " ";
                ans_copy2.push_back(a[n-1]);
                print_subs(dp, a, x-a[n-1], n-1, ans_copy2);
            }
            return;
        }
    }
}

int main()
 {
	int t, n, x;
	cin >> t;
	while (t > 0)   {
	    cin >> n;
	    vector<int> a(n);
	    for (int i=0; i<n; i++) {
	        cin >> a[i];
	    }
	    cin >> x;
	    vector<vector<int> > dp(x+1, vector<int>(n+1, 0));
	    for (int i=0; i<=n; i++) {
	        dp[0][i]=1;
	    }
	    for (int i=0; i<=x; i++) {
	        dp[i][0]=0;
	    }
	    for (int i=1; i<=x; i++)    {
	        for (int j=1; j<=n; j++)    {
	            if (i==a[j-1])
	                dp[i][j] = 1+dp[i][j-1];
	            else if (i>a[j-1])
	                dp[i][j] = dp[i-a[j-1]][j-1]+ dp[i][j-1];
	            else
	                dp[i][j] = dp[i][j-1];
	        }
	    }
	   // for (int i=0; i<=x; i++)    {
	   //     for (int j=0; j<=n; j++)    {
	   //         cout << dp[i][j] << " ";
	   //     }
	   //     cout << endl;
	   // }
	    vector<int> ans;
	    print_subs(dp, a, x, n, ans);
	    for (int i=0; i<my_ans.size(); i++)    {
	        for (int j=0; j<my_ans[i].size(); j++)    {
	            cout << my_ans[i][j] << " ";
	        }
	        cout << endl;
	    }
	    my_ans.clear();
	    cout << dp[x][n] << endl;
	    t--;
	}
	return 0;
}