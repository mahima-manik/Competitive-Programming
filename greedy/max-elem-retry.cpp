#include<vector>
#include<iostream>

using namespace std;

int main()  {
    int n;
    cin >> n;
    vector<int> negs;
    vector<int> poss;
    vector<int> zeros;
    vector<pair<long long int, int> > a(n);
    int c0=0, c1=0, c2=0; 
    long long int temp;
    for (int i=0; i<n; i++) {
        cin >> temp;
        a[i] = make_pair(temp, i);
        if (a[i].first==0)    {
            zeros.push_back(i);
            c0++;
        }
        if (a[i].first<0) {
            negs.push_back(i);
            c1++;
        }
        else    {
            poss.push_back(i);
            c2++;
        }
    }
    //cout << flg0 << " " << flg1 << " " << c0 << " " << c1;
    if (c1%2!=0)   {   //odd number of negatives and no zeroes
        int pos=0;
        for (int i=1; i<c1; i++)  {
            if (a[negs[i]].first<0 && a[negs[i]].first>a[pos].first)
                pos=i;
        }
        if (c0==0)  {   //no 0s are present
            cout << "2 " << negs[pos]+1 << endl;
            a.erase(a.begin()+negs[pos]);
            negs.erase(negs.begin()+pos);
            n--;
        }
        else    {      //0s are present
            int m1 = min(zeros[0], negs[pos]);
            int m2 = max(zeros[0], negs[pos]);
            if (m1==zeros[0])   {
                zeros[0]=m2;
            }
            negs.erase(negs.begin()+pos);
            c1--;
            a[m2].first *= a[m1].first;
            cout << "1 " << m1+1 << " " << m2+1 << "\n";
            a.erase(a.begin()+m1);
            n--;
        }
    }
    if (c0>0)   {   //remove all zeroes from the array
        while (c0 > 0)  {
            [zeros[0]]
        }
        
        int i=flg0, j=i+1;
        while (j<n && c0>0) {
            if (a[j].first==0)    {
                cout << "1 " << a[i].second+1 << " " << a[j].second+1 << "\n";
                a.erase(a.begin()+i);
                i=j-1;
                n--;
                c0--;
            }
            else
                j++;
        }
        if (i<n && j==n && n!=1)    {
            cout << "2 " << a[i].second+1 << "\n";
            a.erase(a.begin()+i);
            n--;
        }
    }
    int i=0;
    while (n>=2) {
        a[i+1].first *= a[i].first;
        cout << "1 " << a[i].second+1 << " " << a[i+1].second+1 << "\n";
        a.erase(a.begin()+i);
        n--;
    }
    return 0;
}