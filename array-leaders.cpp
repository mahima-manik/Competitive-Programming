/*
Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. The rightmost element is always a leader. 

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= A[i]<=100

Example:
Input:
2
6
16 17 4 3 5 2
5
1 2 3 4 0
Output:
17 5 2
4 0
*/
#include<iostream>
using namespace std;

void sprint (int a[], int lead, int last)   {
    if (last >= 0)  {
        if (a[last] > a[lead])  {
            sprint(a, last, last-1);
            cout << a[last] << " ";
        }
        else
            sprint(a, lead, last-1);
        }
}

int main()
 {
	int t, n;
	cin >> t;
	while (t > 0)   {
	    cin >> n;
	    int a[n];
	    for (int i=0; i<n; i++) {
	        cin >> a[i];
	    }
	    sprint (a, n-1, n-2);
	    cout << a[n-1] << " ";
	    /*
	    for (int i=n-1; i >=0; i--) {
	        if (a[i] > a[l])    {
	            l = i;
	            cout << a[l] << " ";
	        }
	    }*/
	    cout << endl;
	    t--;
	}
	return 0;
}