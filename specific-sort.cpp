/*
Given an array of integers (both odd and even), the task is to sort them in such a way that the first part of the array contains odd numbers sorted in descending order, rest portion contains even numbers sorted in ascending order.

Examples:

Input  : A[] = {1, 2, 3, 5, 4, 7, 10}
Output : A[] = {7, 5, 3, 1, 2, 4, 10}

Input  : A[] = {0, 4, 5, 3, 7, 2, 1}
Output : A[] = {7, 5, 3, 1, 0, 2, 4} 


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the array. The next line contains N space separated values of the array.

Output:
For each test case in a new line print the space separated values of the  new transformed array.

Constraints:
1<=T<=100
1<=N<=100
0<=A[]<=100

Example:
Input:
2
7
1 2 3 5 4 7 10
7
0 4 5 3 7 2 1
Output:
7 5 3 1 2 4 10
7 5 3 1 0 2 4
*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
 {
	int t, n, temp;
	cin >> t;
	priority_queue <int> od;
	priority_queue <int, vector<int>, greater<int> > ev;
	while (t > 0)   {
	    cin >> n;
	    int i = 0;
	    while (i < n)   {
	        cin >> temp;
	        if (temp%2 == 0)
	            ev.push(temp);
	        else
	            od.push(temp);
	        i++;
	    }
	    
	    while (od.empty() == false) {
	        cout << od.top() << " ";
	        od.pop();
	    }
	    while (ev.empty() == false) {
	        cout << ev.top() << " ";
	        ev.pop();
	    }
	    cout << endl;
	    t--;
	}
	return 0;
}