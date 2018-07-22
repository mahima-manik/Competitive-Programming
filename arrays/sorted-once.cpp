/*
Given a sorted array of integers, every element appears twice except for one. Find that single one in linear time complexity and without using extra memory.

 

Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line of each test case contains the size of the array, and the second line has the elements of the array.

 


Output:

In each separate line print the number that appears only once in the array.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100000


Example:

Input:

1
11
1 1 2 2 3 3 4 50 50 65 65

Output:

4
*/
#include<iostream>
#include<vector>
using namespace std;

void bsearch (vector<int> a, int b, int e)  {
    if (b==e)   {
        cout << a[b] << endl;
    }
    else if ( b < e)    {
        int mid = (e-b)/2 + 1 + b;
        if ((mid-1)>= b && a[mid] == a[mid-1]) {
            if (mid+1 <= e && (e-mid)%2!=0)
                bsearch(a, mid+1, e);
            if (mid-2 >= b && (mid-1-b)%2!=0)
                bsearch(a, b, mid-2);
            return;
        }
        else if ((mid+1)<=e && a[mid] == a[mid+1]) {
            if (mid-1 >= b && (mid-b)%2!=0)
                bsearch(a, b, mid-1);
            if (mid+2 <= e && (e-mid-1)%2!=0)
                bsearch(a, mid+2, e);
            return;
        }
        else {
            cout << a[mid] << endl;
            return;
        }
    }
}

int main()
 {
	int t, n, m;
	cin >> t;
	while (t > 0)   {
	    cin >> n;
	    vector<int> a(n);
	    for (int i=0; i<n; i++) {
	        cin >> a[i];
	    }
	    
	    int b=0;
	    int e=n-1;
	    bsearch(a, b, e);
	    
	    t--;
	}
	return 0;
}