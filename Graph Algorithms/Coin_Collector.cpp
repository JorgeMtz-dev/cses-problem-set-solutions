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
vector<int>g[MAXN];
vector<int>adj[MAXN];
int dp[MAXN];
int iniCost[MAXN],finCost[MAXN];
int n,m;

vi scc() {
  int t = 0, ncomps = 0;
  vi tin(n), scc(n, -1), z;
  auto dfs = [&](auto&& self, int u) -> int {
    int low = tin[u] = ++t, x; z.push_back(u);
    for (auto v : g[u]) if (scc[v] < 0)
      low = min(low, tin[v] ?: self(self, v));
    if (low == tin[u]) {
      do {
        x = z.back(); z.pop_back();
        scc[x] = ncomps;
      } while (x != u);
      ncomps++;
    }
    return tin[u] = low;
  };
  FOR (i, 0, n) if (scc[i] == -1) dfs(dfs, i);
  return scc;
}

int dfs(int curr){
    if(dp[curr])return dp[curr];
    int maxi = 0;
    for(auto next : adj[curr]){
        maxi = max(maxi,dfs(next));
    }
    return dp[curr] = maxi+finCost[curr];
}

void solve() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++)cin>>iniCost[i];
    for(int i = 0;i < m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }   
    n++;
    auto componente = scc();
    n--;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        finCost[componente[i]] += iniCost[i];
        ans = max(ans,finCost[componente[i]]);
        int u = componente[i];
        for(auto next : g[i]){
            if(componente[next] != u){
                adj[u].push_back(componente[next]);
            }
        }
    }
    
    for(int i = 1;i <= n;i++){
        //existe y no se ha procesado
        if(finCost[i] && !dp[i]){
            dfs(i);
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
}

signed main() {

    fastIO;
    solve();
}