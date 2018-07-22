/*
Given a integer represented as a string, we need to get the sum of all possible sub-strings of this string.

Examples:

Input  : N = “1234”
Output : 1670
Sum = 1 + 2 + 3 + 4 + 12 + 23 +
       34 + 123 + 234 + 1234 
    = 1670

Input  : N = “421”
Output : 491
Sum = 4 + 2 + 1 + 42 + 21 + 421
    = 491


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case in a new line print the required result.

Constraints:
1<=T<=200
1<=N<=10^5+6

Example:
Input:
2
1234
421
Output:
1670
491
*/
#include<iostream>
#include<vector>
#include <string>

using namespace std;
int main()
 {
	int t;
	string s;
	cin >> t;
	while (t > 0)   {
	    cin >> s;
	    int ts = 0;
	    vector<string> strs;
	    
	    for (int i= s.length()-1; i>=0; i--)  {
	        string temp (1, s[i]);
	        ts += stoi(temp);
	        //cout << s[i] << " ";
            
            vector<string>::iterator itr = strs.begin();
            while (itr != strs.end())   {
                *itr = temp + *itr;
                //cout << *itr << " ";
                ts += stoi(*itr);
                itr++;
            }
	        strs.push_back(temp);
	        
	    }
	    cout << ts <<endl;
	    t--;
	}
	return 0;
}