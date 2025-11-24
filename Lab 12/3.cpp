#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n + 1];
    f(i, 0, e)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    function<int(int, int)> dijkstra = [&](int start, int end)->int {
        int dist[n+1];
        f(i, 1,n+1) dist[i] = -1000;
        priority_queue<pair<int,int>> pq;
        pq.push({0,start});
        while(!pq.empty()){
            auto [d1, u]  = pq.top();
            pq.pop();
            for(auto &[d2, v]: adj[u]){
                if(d1 - d2 > dist[v]){
                    dist[v] = d1 - d2;
                    pq.push({dist[v], v});
                }
            }
        }
        return -dist[end];
    };

    cout << dijkstra(1,2) << endl;
    cout << dijkstra(1,4) << endl;
    return 0;
}