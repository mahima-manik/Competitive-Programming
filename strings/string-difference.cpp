/*
Given two strings s1 & s2, remove those characters from first string which are present in second string. Both the strings are different and contain only lowercase characters.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is s1,s1 is first string.
The second line of each test case contains s2,s2 is second string.

Output:

Print the modified string(s1). For each test case, print the output in a new line.

Constraints:

1 ≤ T ≤ 15
1 ≤ s2 < s1 ≤ 50

Example:

Input:
2
geeksforgeeks
mask
removeccharaterfrom
string

Output:
geeforgee

emovecchaaefom
*/
#include<iostream>
#include<string>
using namespace std;
int main()
 {
	int t;
	cin >> t;
	string s1, s2;
	while (t > 0)   {
	    cin >> s1;
	    cin >> s2;
	    
	    for (int i=0; i<s2.length(); i++)   {
	        int pos = s1.find(s2[i]);
	        while (pos < s1.length() && pos >= 0)   {
	            s1.erase(pos, 1);
	            pos = s1.find(s2[i]);
	        }
	    }
	    cout << s1 << endl;
	    t--;
	}
	return 0;
}