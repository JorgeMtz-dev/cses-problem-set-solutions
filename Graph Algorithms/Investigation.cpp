//Author: 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define fastIO ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
#define int long long
#define V vector
#define pb push_back
#define pf push_front
#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define all(v) v.begin(),v.end()
#define endl '\n'
#define SZ(x) (int)x.size()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
using pi = pair<int, int>;

constexpr ull MOD2 = (1ULL<<32);
constexpr int MOD = 1e9+7;
constexpr int MAXN = 2e5+5;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};  // abajo, derecha, arriba, izquierda
typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void show(vector<int>&arr){
  for(auto x : arr){
      cout<< x <<' ';
  }
  cout << endl;
}

void dijkstra(int start,int end, vector<vector<pair<int, int>>> &graph) {
    const int INF = LLONG_MAX;
    int n = graph.size();
    vector<int> dist(n + 1, INF),paths(n+1,0),minRoute(n+1,LLONG_MAX),maxRoute(n+1,0);
    dist[start] = 0;
    paths[start] = 1;
    minRoute[start] = 0;
    maxRoute[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if (du > dist[u])
            continue;

        for (auto &[v, dv] : graph[u]) {
            if (du + dv < dist[v]) {
                dist[v] = du + dv;
                paths[v]=paths[u];
                minRoute[v] = minRoute[u]+1;
                maxRoute[v] = maxRoute[u]+1;
                pq.emplace(dist[v], v);
            }else if(du + dv == dist[v]){
                paths[v] = (paths[v] + paths[u]) % MOD;
                if(minRoute[v] > minRoute[u]+1){
                    minRoute[v] = minRoute[u]+1;
                }
                if(maxRoute[v] < maxRoute[u]+1){
                    maxRoute[v] = maxRoute[u]+1;
                }
            }
        }
    }

    cout<<dist[end]<<' '<<paths[end]<<' '<<minRoute[end]<<' '<<maxRoute[end]<<endl;
}

void solve() {
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>>g(n+1);
    for(int i = 0;i < m;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].emplace_back(v,w);
        //g[v].emplace_back(u,w);
    }
    dijkstra(1,n,g);
    
}

signed main() {

    fastIO;
    solve();
}