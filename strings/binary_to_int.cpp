/*
Given two binary strings that represent value of two integers, find the product of two strings. For example, if the first bit string is “1100” and second bit string is “1010”, output should be 120.

Input:
First line consists of T test cases. Only line of every test case consists of 2 binary strings.

Output:
Single line output, print the multiplied value.

Constraints:
1<=T<=100
1<=Length of string<=100

Example:
Input:
2
1100 01
01 01
Output:
12
1
*/
#include<iostream>
using namespace std;
int main()
 {
	int t;
	string a, b;
	cin >> t;
	while (t > 0)   {
	    cin >> a >> b;
	    int i = stoi(a, nullptr, 2);
	    int j = stoi(b, nullptr, 2);
	    cout << i*j<< endl;
	    t--;
	}
	return 0;
}