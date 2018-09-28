#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int _size,N;
        cin>>_size>>N;
        Graph *g = new Graph(_size);
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g->addEdge(u,v);
        }
        cout<<g->isCyclic()<<endl;
    }
}
void dfs (vector<int> &vis, int pos, list<int> *adj, int &flg, vector<int> ancs)    {
    if (flg==0)     {
        vis[pos] = 1;
        int n = adj[pos].size();
        //cout << pos << " " << adj[pos].size() << "\n";
        vector<int> temp(ancs.begin(), ancs.end());
        temp.push_back(pos);
        while (!adj[pos].empty())    {
            //cout << source << " " << pos << " " << adj[pos].front() << " " << vis[adj[pos].front()] << " \n";
            if (vis[adj[pos].front()] == 1)    {
                if (adj[pos].front() == pos)   {
                    flg = 1;
                    adj[pos].pop_front();
                    //cout << "here2\n";
                    return;
                }
                if (find(ancs.begin(), ancs.end(), adj[pos].front()) != ancs.end())    {
                    flg = 1;
                    adj[pos].pop_front();
                    //cout << "here2\n";
                    return;
                }
                else    {
                    adj[pos].pop_front();
                }
            }
            else    {
                //cout << "here3\n";
                int k = adj[pos].front();
                adj[pos].pop_front();
                
                dfs(vis, k, adj, flg, temp);
            }
        }
    }
    else
        return;
}
bool Graph :: isCyclic()    {
    vector<int> vis(V, 0);
    int flg = 0;
    for (int i=0; i<V; i++) {
        if (flg == 1)
            break;
        if (vis[i]==0 && flg==0 && adj[i].size()>0)    {
            //cout << "called " << i << "\n";
            vector<int> temp(1, -1);
            dfs(vis, i, adj, flg, temp);
        }
    }
    if (flg == 1)
        return true;
    else 
        return false;
}