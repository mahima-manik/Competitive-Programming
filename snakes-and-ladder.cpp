/*
Hackerrank
Markov takes out his Snakes and Ladders game, stares at the board and wonders: "If I can always roll the die to whatever number I want, what would be the least number of rolls to reach the destination?"

Rules The game is played with a cubic die of  faces numbered  to .

Starting from square , land on square  with the exact roll of the die. If moving the number rolled would place the player beyond square , no move is made.

If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.

If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.

Function Description

Complete the quickestWayUp function in the editor below. It should return an integer that represents the minimum number of moves required.

quickestWayUp has the following parameter(s):

ladders: a 2D integer array where each  contains the start and end cell numbers of a ladder
snakes: a 2D integer array where each  contains the start and end cell numbers of a snake
Input Format

The first line contains the number of tests, .

For each testcase: 
- The first line contains , the number of ladders. 
- Each of the next  lines contains two space-separated integers, the start and end of a ladder. 
- The next line contains the integer , the number of snakes. 
- Each of the next  lines contains two space-separated integers, the start and end of a snake.

Constraints

 

The board is always  with squares numbered  to . 
Neither square  nor square  will be the starting point of a ladder or snake. 
A square will have at most one endpoint from either a snake or a ladder.

Output Format

For each of the t test cases, print the least number of rolls to move from start to finish on a separate line. If there is no solution, print -1.
*/

#include <bits/stdc++.h>
using namespace std;

int quickestWayUp(unordered_map<int, int> ladders, unordered_map<int, int> snakes) {
    unordered_map<int, int> umap;
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    umap[1] = 0;
    pair<int, int> temp;
    int ans = INT_MAX, l, s;
    while (!q.empty())   {
        temp = q.front();
        //cout << temp.first << " " << temp.second << "\n";
        q.pop();
        if (temp.second > ans)
            continue;
        for (int i=1; i<=6; i++)   {
            if (umap.find(temp.first+i) == umap.end() || (umap[temp.first+i] > temp.second+1))  {
                if (temp.first+i == 100)   {
                    if (ans > temp.second+1)
                        ans = temp.second+1;
                    //break;
                }
                else if (temp.first+i < 100)   {
                    if (ladders.find(temp.first+i) != ladders.end())   {
                        if (ladders[temp.first+i] == 100)   {
                            if (ans > temp.second+1)
                                ans = temp.second+1;
                            //break;
                        }
                        else if (temp.second+1<ans && (umap.find(ladders[temp.first+i]) == umap.end() || umap[ladders[temp.first+i]] > temp.second+1 || umap.find(temp.first+i) == umap.end() || umap[temp.first+i] > temp.second+1)) {
                            q.push(make_pair(ladders[temp.first+i], temp.second+1));
                            umap[ladders[temp.first+i]] = temp.second+1;
                            umap[temp.first+i] = temp.second+1;
                        }
                    }
                    else    {
                        if (snakes.find(temp.first+i) != snakes.end() && temp.second+1<ans && (umap.find(snakes[temp.first+i]) == umap.end() || umap[snakes[temp.first+i]] > temp.second+1 || umap.find(temp.first+i) == umap.end() || umap[temp.first+i] > temp.second+1)) {
                            q.push(make_pair(snakes[temp.first+i], temp.second+1));
                            umap[snakes[temp.first+i]] = temp.second+1;
                            umap[temp.first+i] = temp.second+1;
                        }
                        else if (temp.second+1<ans) {
                            q.push(make_pair(temp.first+i, temp.second+1));
                            umap[temp.first+i] = temp.second+1;
                        }
                    }
                }
                else
                    break;
            }
        }
    }
    if (ans == INT_MAX)
        ans=-1;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        unordered_map<int, int> lad;
        unordered_map<int, int> snak;
        for (int i=0; i<n; i++) {
            lad[ladders[i][0]] = ladders[i][1];
        }
        for (int i=0; i<m; i++) {
            snak[snakes[i][0]] = snakes[i][1];
        }
        int result = quickestWayUp(lad, snak);
        cout<<result<<endl;
        cout << result << "\n";
    }


    return 0;
}