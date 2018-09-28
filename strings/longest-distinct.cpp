/*Given a string, find length of the longest substring with all distinct characters.  For example, for input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is String str.

Output:

Print length of smallest substring with maximum number of distinct characters.
Note: The output substring should have all distinct characters.

Constraints:

1 ≤ T ≤ 100
1 ≤ size of str ≤ 10000

Example:

Input
2
abababcdefababcdab
geeksforgeeks
 

Output:
6
7*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()
 {
	int t;
    string str;
	cin >> t;
	while (t > 0)   {
	    cin >> str;
	    unordered_map<char, int> umap;
	    int max_len = 0;
	    int i=0;
	    int j=1;
	    umap[str[0]] = 1;
	    max_len = umap.size();
	    while ( i <= j && j<str.length()) {
	        if (umap.find(str[j]) != umap.end())    {   //found
	            umap.erase(str[i]);
	            i++;
	        }
	        else {  //not found
	            umap[str[j]] = 1;
	            j++;
	            if (max_len < umap.size())
	                max_len = umap.size();
	        }
	        
	    }
	    cout << max_len << endl;
	    t--;
	}
	return 0;
}