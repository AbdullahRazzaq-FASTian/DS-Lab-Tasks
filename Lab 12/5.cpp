#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
#define N 15
using namespace std;

int adj_list[N+1][N+1];   
int deg[N+1];             
int adj_matrix[N+1][N+1]; 
bool visited[N+1];

void dfs(int u)
{
    cout << u << " ";
    visited[u] = true;

    f(i,0,deg[u])
    {
        int v = adj_list[u][i];
        if(!visited[v])
            dfs(v);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        cout << u << " ";

        f(i,0,deg[u])
        {
            int v = adj_list[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    f(i,0,e)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u][deg[u]++] = v;
        adj_list[v][deg[v]++] = u;

        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    nl;
    cout << "Adjacency List:\n";
    f(i,1,n+1)
    {
        cout << i << " -> ";
        f(j,0,deg[i])
            cout << adj_list[i][j] << " ";
        nl;
    }

    nl;

    cout << "Adjacency Matrix:\n";
    f(i,1,n+1)
    {
        f(j,1,n+1)
            cout << adj_matrix[i][j] << " ";
        nl;
    }

    nl;

    memset(visited,false,sizeof(visited));
    cout << "DFS Traversal: ";
    dfs(1);
    nl;

    memset(visited,false,sizeof(visited));
    cout << "BFS Traversal: ";
    bfs(1);
    nl;

    return 0;
}

/* 
5 5
1 4
2 4
2 5
4 5
3 5
*/