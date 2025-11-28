#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define N 15
using namespace std;

int main()
{
    int n, e, start, end;
    cin >> n >> e >> start >> end;

    int adj_u[N + 1][N + 1] = {0};
    int adj_w[N + 1][N + 1] = {0}; 
    int deg[N + 1] = {0}; 
    // cout << "here" << endl;
    f(i, 0, e)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_u[u][deg[u]] = v; 
        adj_w[u][deg[u]] = w;
        deg[u]++;

        adj_u[v][deg[v]] = u;
        adj_w[v][deg[v]] = w;
        deg[v]++;
    }

    function<int(int, int)> dijkstra = [&](int start, int end) -> int
    {
        int dist[n + 1];
        f(i, 1, n + 1) dist[i] = 1000;
        dist[start] = 0;

        priority_queue<pair<int, int>> pq;
        pq.push({-dist[start], start});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            f(i, 0, deg[u])
            {
                int v = adj_u[u][i];
                int w = adj_w[u][i];

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({-dist[v], v});
                }
            }
        }
        
        // for(auto &it: dist) cout << it << " ";

        return dist[end];
    };

    nl;
    cout << "Shortest distance frome " << start << " to " << end << " is: " << dijkstra(start, end) << endl;
    nl;
    
    return 0;
}

/* 
6 7 1 2
1 2 4
1 4 8
2 3 9 
3 4 6
3 5 14
4 6 4
5 6 3
*/