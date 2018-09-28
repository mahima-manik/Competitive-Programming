#include<iostream>
#include<string>
#include <vector>

using namespace std;

int main()  {
    string st;
    cin >> st;
    int n = st.size();
    vector<int> freq(26, 0);
    for (int i=0; i<n; i++) {
        freq[st[i]-'a'] += 1;
    }
    int i=0;
    char min_elm = ' ';
    int min_pos = -1;
    vector<int> local_freq(26, 0);
    while (i<n) {
        if (local_freq[st[i]-'a']==0) {
            local_freq[st[i]-'a'] = 1;
            if (min_elm == ' ') {
                min_elm = st[i];
                min_pos = i;
            }
        }
        else    {

        }
    }
    return 0;
}