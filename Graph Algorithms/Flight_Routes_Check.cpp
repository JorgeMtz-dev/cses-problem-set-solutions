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

vector<pair<int,int>> scc(vector<vi>& g) {
  int n = SZ(g), t = 0, ncomps = 0;
  vi tin(n),z;
  vector<pair<int,int>> scc(n, {-1,-1});
  auto dfs = [&](auto&& self, int u) -> int {
    int low = tin[u] = ++t, x; z.push_back(u);
    for (auto v : g[u]) if (scc[v].first < 0)
      low = min(low, tin[v] ?: self(self, v));
    if (low == tin[u]) {
      do {
        x = z.back(); z.pop_back();
        scc[x].first = ncomps;
        scc[x].second = x;
      } while (x != u);
      ncomps++;
    }
    return tin[u] = low;
  };
  FOR (i, 0, n) if (scc[i].first == -1) dfs(dfs, i);
  return scc;
}
bool vis[MAXN];
bool dfs(int curr,int obj,vector<vector<int>>&g){
    if(curr == obj)return true;
    vis[curr]=true;
    for(auto next : g[curr]){ 
        if(!vis[next]){
            if(dfs(next,obj,g))return true;
        }
    }
    return false;
}

void solve() {
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n+1);
    for(int i = 0;i < m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }
    auto ans = scc(g);
    sort(all(ans));
    if(ans[n].first != 1){
        cout<<"NO"<<endl;
        if(dfs(ans[1].second,ans[n].second,g)){
            cout<<ans[n].second<<' '<<ans[1].second<<endl;
        }else{
            cout<<ans[1].second<<' '<<ans[n].second<<endl;
        }
    }else{
        cout<<"YES"<<endl;
    }
}

signed main() {

    fastIO;
    solve();
}