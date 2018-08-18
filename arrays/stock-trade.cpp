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
	    for(int i=0; i<n; i++)  {
	        cin >> a[i];
	    }
	    int i=0;
	    int fbuy = 0;
	    int flg = 0;
	    while (i < n)   {
	        while (a[i] <= a[i+1] && i<n)  {
	            if (fbuy == 0 && i != n-1)  {
	                cout << "(" << i << " ";
	                fbuy = 1;
	                flg = 1;
	            }
	            i++;
	        }
	        while (a[i] >= a[i+1] && i<n)  {
	            if (fbuy == 1)  {
	                cout << i << ")" << " ";
	                fbuy = 0;
	            }
	            i++;
	        }
	        if (i==n && fbuy==1)
	            cout << n-1 << ")" << " ";
	    }
	    if (flg == 0)
	        cout << "No Profit";
	    cout << endl;
	    t--;
	}
	return 0;
}
