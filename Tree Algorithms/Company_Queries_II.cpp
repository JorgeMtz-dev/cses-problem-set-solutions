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
const int LOG  = 21;

vector<int> g[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int curr,int p){

    up[curr][0] = p;
    for(int i = 1; i < LOG;i++){
        up[curr][i] = up[up[curr][i - 1]][i - 1];
    }

    for(auto next : g[curr]){
        if(next == p)continue;
        depth[next] = depth[curr]+1; 
        dfs(next,curr);
    }

}

int lift(int v,int k){

    for(int i = 0;i < LOG;i++){
        if((1<<i)&k){
            v = up[v][i];
        }
    }
    return v;
}

int lca(int u,int v){

    if(depth[u] < depth[v])swap(u,v);

    u = lift(u,depth[u]-depth[v]);

    if(u == v)return v;

    for(int i = LOG-1 ;i >= 0;i--){

        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }

    }
    return up[u][0];

}

void solve() {
    
    int n,q;cin>>n>>q;
    for(int i = 2;i <= n;i++){
        int u;cin>>u;
        g[u].push_back(i);
        g[i].push_back(u);
    }
    
    dfs(1,0);

    while(q--){

        int u,v;cin>>u>>v;

        cout<<lca(u,v)<<endl;

    }
}

int main() {

    fastIO;
    solve();
}