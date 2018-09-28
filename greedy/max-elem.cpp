#include<vector>
#include<iostream>

using namespace std;

int main()  {
    int n;
    cin >> n;
    vector<pair<long long int, int> > a(n);
    int flg0=-1, flg1=-1, c0=0, c1=0;
    long long int temp;
    for (int i=0; i<n; i++) {
        cin >> temp;
        a[i] = make_pair(temp, i);
        if (a[i].first==0)    {
            if (flg0==-1)
                flg0=i;
            c0++;
        }
        if (a[i].first<0) {
            if (flg1==-1)
                flg1=i;
            c1++;
        }
    }
    //cout << flg0 << " " << flg1 << " " << c0 << " " << c1;
    if (c1%2!=0)   {   //odd number of negatives and no zeroes
        int pos=flg1;
        for (int i=flg1+1; i<n; i++)  {
            if (a[i].first<0 && a[i].first>a[pos].first)
                pos=i;
        }
        if (c0==0)  {
            cout << "2 " << pos+1 << endl;
            a.erase(a.begin()+pos);
            n--;
        }
        else    {      
            int m1 = min(pos, flg0);
            int m2 = max(pos, flg0);
            a[m2].first *= a[m1].first;
            cout << "1 " << m1+1 << " " << m2+1 << "\n";
            a.erase(a.begin()+m1);
            n--;
            if (m1==flg0)   {
                if (c0==1)
                    flg0=m2-1;
                else    {
                    for (int i=m1; i<n; i++)    {
                        if (a[i].first==0)    {
                            flg0=i;
                            break;
                        }
                    }    
                }
            }
            else if (m1==pos)
                flg0--;
        }
    }
    if (c0>0)   {   //remove all zeroes from the array
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
        //a[i+1].first *= a[i].first;
        cout << "1 " << a[i].second+1 << " " << a[i+1].second+1 << "\n";
        a.erase(a.begin()+i);
        n--;
    }
    return 0;
}