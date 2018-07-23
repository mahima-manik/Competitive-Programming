/*
Given an array of n words. Some words are repeated twice, we need count such words.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the number of words in the string. The next line contains n space separated words forming the string.

Output:
Print the count of the words which are repeated twice in the string.

Constraints:
1<=T<=105  
1<=no of words<=105
1<=length of each word<=105

Example:
Input:
2
10
hate love peace love peace hate love peace love peace
8
Tom Jerry Thomas Tom Jerry Courage Tom Courage

Output:
1
2
*/
#include<iostream>
#include<string>
#include <bits/stdc++.h>

using namespace std;
int main()
 {
	int t, n;
	string str;
	cin >> t;
	while (t > 0)   {
	    cin >> n;
	    cin.ignore();
	    getline(cin, str);
        vector<string> s;
	    int len = str.length();
	    int i=0;
	    while (i < len)    {
	        string wrd;
	        int pos;
	        if (str.find(" ", i) != std::string::npos) {
	            pos = str.find(" ", i);
	            wrd = str.substr(i, pos-i);
	            s.push_back(wrd);
	            //cout << wrd << " " << i << " -> "<< pos+1 << endl;
	            i = pos+1;
	        }
	        else    {
	            wrd = str.substr(i, len-i);
	            s.push_back(wrd);
	            //cout << wrd << " " << i << " -> "<< pos+1 << endl;
	            break;
	        }
	    }

	    unordered_map<string, int> m;
        for (int i = 0; i < n; i++)
            m[s[i]] += 1;
     
        int res = 0;
        for (auto it = m.begin(); it != m.end(); it++)
            if ((it->second == 2))
                res++;
     
        cout << res << endl;
	    t--;
	}
	return 0;
}