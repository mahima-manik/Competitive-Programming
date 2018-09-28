/*
All submissions for this problem are available.
There was a big fight between the brothers Ram and Shyam as to who would play on the computer. Their mother got irritated and in order to quiten them thought up a game. 
They were given a string s, consisting of lowercase English letters. They play a game that is described by the following rules:

The players move in turns; In one move the player can remove an arbitrary letter from string s.
If the player before his turn can reorder the letters in string s so as to get a palindrome, this player wins. A palindrome is a string that reads the same both ways (from left to right, and vice versa). For example, string "abba" is a palindrome and string "abc" isn't.
Determine which player will win, provided that both sides play optimally well the one who moves first(Ram) or the one who moves second(Shyam).The brother winning will play his favourite game!

Input:
The input contains a single line, containing string s . String s consists of lowercase English letters.

Output: 
In a single line print word "Ram" if the first player wins (provided that both players play optimally well). Otherwise, print word "Shyam". Print the words without the quotes.

Sample Input 1:
aba

Sample Output 1:
Ram

Sample Input 2:
abca

Sample Output 2:
Shyam

Constraints:
1<=|s|<=10^6
Time Limit:1 s
*/
#include<iostream>
#include<string>
#include <vector>

using namespace std;

int main()  {
    string st;
    cin >> st;
    int n = st.size();
    vector<int> umap(26, 0);
    for (int i=0; i<n; i++) {
        umap[st[i]-'a'] += 1;
    }
    int odd_occ = 0;
    int even_occ = 0;
    for (int i=0; i<26; i++) {
        //cout << umap[i] << " ";
        if (umap[i]>0 && umap[i]%2==0)
            even_occ++;
        else if (umap[i]>0 && umap[i]%2!=0)
            odd_occ++;
    }
    //cout << endl;
    int turn=0;
    while (odd_occ>1)  {
        turn++;
        if (even_occ>0 && odd_occ==2)    {
            // delete any even
            for (int i=0; i<26; i++)    {
                if (umap[i]>0 && umap[i]%2==0)  {
                    umap[i]-=1;
                    if (umap[i]>0)  {
                        odd_occ++;
                        even_occ--;
                    }
                    else
                        even_occ--;
                    break;
                }
            }
        }
        else if ((even_occ>0 && odd_occ>2) || (even_occ==0 && odd_occ>=2))   {
            // delete any odd
            for (int i=0; i<26; i++)    {
                if (umap[i]>0 && umap[i]%2!=0)  {
                    umap[i]-=1;
                    if (umap[i]>0)  {
                        odd_occ--;
                        even_occ++;
                    }
                    else
                        odd_occ--;
                    break;
                }
            }
        }
    }
    if (turn%2==0)
        cout << "Ram";
    else
        cout << "Shyam";
    
    return 0;
}