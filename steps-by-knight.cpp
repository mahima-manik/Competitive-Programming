#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t, n, x1, y1, x2, y2;
	cin >> t;
	while (t > 0)   {
	    cin >> n >> x1>>y1>>x2>>y2;
	    vector<vector<int>> board(n+1, vector<int>(n+1, 0));
	    queue<pair<pair<int, int>, int>> q;
	    q.push(make_pair(make_pair(x1, y1), 0));
	    board[x1][y1] = 1;
	    pair<pair<int, int>, int> temp;
	    while (!q.empty())  {
	        //cout << q.size() << " ";
	        temp = q.front();
	        q.pop();
	        cout << temp.first.first << " " << temp.first.second << " " << temp.second << "\n";
	        if (temp.first.first == x2 && temp.first.second == y2)  {
	            cout << temp.second;
	            break;
	        }
	        else    {
	            if (x1-2>=1 && y1-1>=1 && board[x1-2][y1-1] == 0)   {
	                board[x1-2][y1-1] = 1;
	                q.push(make_pair(make_pair(x1-2, y1-1), temp.second+1));
	                if (x1-2==x2 && y1-1==y2)   {
	                    cout << temp.second+1;
	                    break;
	                }
	            }
	            if (x1-2>=1 && y1+1<=n && board[x1-2][y1+1] == 0)   {
	                q.push(make_pair(make_pair(x1-2, y1+1), temp.second+1));
	                board[x1-2][y1+1] = 1;
	                if (x1-2==x2 && y1+1==y2)   {
	                    cout << temp.second+1;
	                    break;
	                }
	            }
	            if (x1-1>=1 && y1+2<=n && board[x1-1][y1+2] == 0)   {
	                q.push(make_pair(make_pair(x1-1, y1+2), temp.second+1));
	                board[x1-1][y1+2] = 1;
	                if (x1-1==x2 && y1+2==y2)   {
	                    cout << temp.second+1;
	                    break;
	                }
	            }
	            if (x1+1<=n && y1+2<=n && board[x1+1][y1+2] == 0)   {
	                q.push(make_pair(make_pair(x1+1, y1+2), temp.second+1));
	                board[x1+1][y1+2] = 1;
	                if (x1+1==x2 && y1+1==y2)   {
	                    cout << temp.second+1;
	                    break;
	                }
	            }
	            if (x1+2<=n && y1+1<=n && board[x1+2][y1+1] == 0)   {
	                q.push(make_pair(make_pair(x1+2, y1+1), temp.second+1));
	                board[x1+2][y1+1] = 1;
	                if (x1+2==x2 && y1+1==y2)   {
	                    cout << temp.second+1;
	                    break;
	                }
	            }
	            if (x1+2<=n && y1-1>=1 && board[x1+2][y1-1] == 0)   {
	                q.push(make_pair(make_pair(x1+2, y1-1), temp.second+1));
	                board[x1+2][y1-1] = 1;
	                if (x1+2==x2 && y1-1==y2)   {
	                    cout << temp.second+1;
	                    break;
	                }
	            }
	            if (x1+1<=n && y1-2>=1 && board[x1+1][y1-2] == 0)   {
	                q.push(make_pair(make_pair(x1+1, y1-2), temp.second+1));
	                board[x1+1][y1-2] = 1;
	                if (x1+1==x2 && y1-2==y2)   {
	                    cout << temp.second+1;
	                    break;
	                }
	            }
	            if (x1-1>=1 && y1-2>=1 && board[x1-1][y1-2] == 0)   {
	                q.push(make_pair(make_pair(x1-1, y1-2), temp.second+1));
	                board[x1-1][y1-2] = 1;
	                if (x1-1==x2 && y1-2==y2)   {
	                    cout << temp.second+1;
	                    break;
	                }
	            }
	        }
	    }
	    cout << endl;
	    t--;
	}
	return 0;
}