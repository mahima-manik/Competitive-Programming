#include<iostream>
using namespace std;

class Graph {
    public:
        int v;
        int **adj_list;
        Graph (int v);
        void addEdge(int start, int end);
        void printCycle();
        void helper(int vis[], int pos, int &flg, int ansc[]);
};

Graph::Graph(int v) {
    this->v = v;
    this->adj_list =  new int*[v];
    for(int i = 0; i<v; i++)
    {
        adj_list[i] = new int[v];
        for (int j=0; j<v; j++) {
            adj_list[i][j] = 0;
        }
    }
}

void Graph::addEdge(int start, int end)  {
    if (start>=0 && start<v && end>=0 && end<v) {
        adj_list[start][end] = 1;
    }
}

void Graph::helper(int vis[], int pos, int &flg, int ansc[])   {
    //cout << "\nreached " << pos;
    ansc[pos] = 1;
    vis[pos] = 1;
    for (int i=0; i<v; i++) {
        if (adj_list[pos][i] == 1)  {   //for vertex adjacent to this pos
            if (vis[i]==1)  {
                if (ansc[i]==1) {   //this vertex is in the anscestors
                    flg = 1;
                    return;
                }
            }
            else    {
                //adj_list[pos][i]=0;
                helper(vis, i, flg, ansc);
            }
        }
    }
    ansc[pos] = 0;
}

void Graph::printCycle()    {
    int vis[v];
    for (int i=0; i<v; i++) {
        vis[i] = 0;
    }
    int flg = 0;
    for (int i=0; i<v; i++) {
        if (flg==1)
            break;
        if (vis[i]==0)  {
            int ansc[v];
            for (int i=0; i<v; i++) {
                ansc[i] = 0;
            }
            helper(vis, i, flg, ansc);
            if (flg==1) {
                cout << "\nCycle detected ";
                for (int i=0; i<v; i++) {
                    cout << ansc[i] << " ";
                }
                cout << endl;
            }
        }
    }
}
int main()  {
    Graph *g = new Graph(5);
    int **adjs = g->adj_list;
    //printing the adjacency matrix
    for (int i=0; i<g->v; i++)  {
        for (int j=0; j<g->v; j++)  {
            cout << adjs[i][j] << " ";
        }
        cout << endl;
    }
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(2, 3);
    g->addEdge(3, 4);
    g->addEdge(0, 4);
    g->printCycle();
    int arr[5] = {4, 2, 7, 1, 3};
    sort(arr, arr+5);
    for (int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    // //printing the adjacency matrix
    // for (int i=0; i<g->v; i++)  {
    //     for (int j=0; j<g->v; j++)  {
    //         cout << adjs[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}