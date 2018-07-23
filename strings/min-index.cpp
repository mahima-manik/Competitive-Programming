/*
Given a string str and another string patt. Find the character in patt that is present at the minimum index in str. If no character of patt is present in str then print ‘No character present’.

Input:
The first line of input contains an integer T denoting the number of test cases. Then the description of T test cases follow. Each test case contains two strings str and patt respectively.

Output:
Print the character in patt that is present at the minimum index in str.
Print "No character present" (without quotes) if no character of patt is present in str.

Constraints:
1<=T<=10^5
1<=length of string<=10^5

Example:
Input:
2
geeksforgeeks
set
adcffaet
onkl

Output:
e
No character present
*/
#include<iostream>
#include<string>
using namespace std;
int main()
 {
	int t;
	string str, patt;
	cin >> t;
	int pind = -1;
	while (t > 0)   {
	    cin >> str >> patt;
	    int minind = str.length() + 1;
	    
	    for (int i=0; i<patt.length(); i++) {
	        if (str.find(patt[i]) != std::string::npos) {
	            if (str.find(patt[i]) < minind) {
	                minind = str.find(patt[i]);
	                pind = i;
	            }
	        }
	    }
	    if (pind != -1)
	        cout << patt[pind] << endl;
	    else
	        cout << "No character present" << endl;
	    t--;
	}
	return 0;
}