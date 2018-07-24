/*
As usual Babul is again back with his problem and now with numbers. He thought of an array of numbers in which he does two types of operation that is rotation and deletion. His process of doing these 2 operations are that he first rotates the array in a clockwise direction then delete the last element. In short he rotates the array nth times and then deletes the nth last element. If the nth last element does not exists then he deletes the first element present in the array. So your task is to find out which is the last element that he deletes from the array so that the array becomes empty after removing it.

For example
A = {1,2,3,4,5,6}.

He rotates the array clockwise i.e. after rotation the array A = {6,1,2,3,4,5} and delete the last element that is {5} so A = {6,1,2,3,4}. Again he rotates the array for the second time and deletes the second last element that is {2} so A = {4,6,1,3}, doing these steps when he reaches 4th time, 4th last element does not exists so he deletes 1st element ie {1} so A={3,6}. So continuing this procedure the last element in A is {3}, so o/p will be 3.
 

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains an integer N. Then in the next line are N space separated values of the array A.
 

Output:
For each test case in a new line print the required result.
 

Constraints:
1<=T<=200
1<=N<=100
1<=A[i]<=10^7
 

Example:
Input
2
4
1 2 3 4
6
1 2 3 4 5 6

Output:
2
3
*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, n;
	cin >> t;
	while (t > 0)   {
	    cin >> n;
	    vector<int> a(n);
	    for (int i=0; i<n; i++) {
	        cin >> a[i];
	    }
	    int num = 1;
	    while (num < n)    {
    	    //rotate
    	    int temp= num%a.size();
    	        
    	    rotate(a.begin(), a.begin()+a.size()-1, a.end());
    	    /*cout << "For num, temp =" << num << " " << temp << "\t";
        	for (int i=0; i<a.size(); i++) {
        	        cout << a[i] << " ";
        	}
        	cout << endl;*/
    	    //erase
    	    if (num <= a.size())
    	        a.erase(a.end()-num);
    	    else
    	        a.erase(a.begin());

    	    /*cout << "For num, temp =" << num << " " << temp << "\t";
        	for (int i=0; i<a.size(); i++) {
        	        cout << a[i] << " ";
        	}
        	cout << endl;*/
    	    
    	    num++;
    	    //cout << endl;
	    }
	    //cout << "For num =" << num << "\t";
    	for (int i=0; i<a.size(); i++) {
    	        cout << a[i] << endl;
    	}
	    //cout<<endl;
	    t--;
	}
	return 0;
}