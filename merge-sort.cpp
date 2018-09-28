#include<iostream>
#include<vector>
using namespace std;

int inv = 0;
void merge (vector<int> &A, int l, int m, int r)  {
    int n1 = m-l+1;
    int n2 = r-m;
    vector<int> L(n1);
    vector<int> R(n2);
    for (int i = 0; i < n1; i++) 
        L[i] = A[l + i]; 
    for (int j = 0; j < n2; j++) 
        R[j] = A[m + 1 + j];
    int i=0, j=0;
    int c=l;
    while (i<n1 || j<n2)  {
        if (i==n1)  {
            A[c] = R[j];
            j++;
        }
        else if (j==n2) {
            A[c] = L[i];
            i++;
        }
        else if (L[i]<=R[j])  {
            A[c]=L[i];
            i++;
        }
        else  {
            A[c]=R[j];
            j++;
            inv += (n1 - i);
        }
        c++;
    }
}

void mergesort(vector<int> &A, int l, int r) {
    if (l<r)    {
        int mid = (r-l)/2 + l;
        mergesort(A, l, mid);
        mergesort(A, mid+1, r);
        merge(A, l, mid, r);
    }
}

int main()  {
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(5);
    // cout << arr.size();
    mergesort(arr, 0, arr.size()-1);
    for (int i=0; i<arr.size(); i++)    {
        cout << arr[i] << " ";
    }
    cout << inv;
    return 0;
}