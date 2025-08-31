//Author: 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define fastIO ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
 
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
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
using pi = pair<int, int>;
 
constexpr ull MOD2 = (1ULL<<32);
constexpr int MOD = 1e9+7;
constexpr int MAXN = 1e5+5;
 
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
 
vector<vector<int>> dijkstra(int start, vector<vector<pair<int, int>>> &graph) {
    const int INF = 1e18;
    int n = graph.size();
    vector<vector<int>> dist(n + 1, vector<int>(2,INF));
    dist[start][0] = 0;
 
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.emplace(0, start, 0);
    while (!pq.empty()) {
        auto [du, u, used] = pq.top();
        pq.pop();
 
        if (du > dist[u][used])
            continue;
 
 
        for (auto &[v, w] : graph[u]) {
            
            if (dist[v][used] > dist[u][used] + w) {
                dist[v][used] = dist[u][used] + w;
                pq.emplace(dist[v][used], v, used);
            }

            if (!used) {
                int half = w / 2;
                if (dist[v][1] > dist[u][0] + half) {
                    dist[v][1] = dist[u][0] + half;
                    pq.emplace(dist[v][1], v, 1);
                }
            }
        }
 
    }
 
    return dist;
}
 
 
void solve() {
    
    int n,m;cin>>n>>m;
    vector<vector<pair<int, int>>>grafo(n,vector<pair<int,int>>());
    for(int i = 0;i < m;i++){
        int a,b,w;cin>>a>>b>>w;
        a--;b--;
        grafo[a].push_back({b,w});
    }
    auto dist = dijkstra(0,grafo);
    cout << min(dist[n - 1][0], dist[n - 1][1]) << endl;
}   
 
signed main() {
 
    fastIO;
    solve();
}