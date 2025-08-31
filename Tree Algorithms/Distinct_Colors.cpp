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

vector<int>adj[MAXN];
int ans[MAXN];
int color[MAXN];

set<int>dfs(int curr,int p){
    set<int>ahora;
    ahora.insert(color[curr]);
    for(auto next : adj[curr]){
        if(next == p)continue;

        set<int> antes = dfs(next,curr);

        if(SZ(antes) > SZ(ahora))swap(antes,ahora);

        ahora.merge(antes);

    }
    ans[curr] = SZ(ahora);
    return ahora;    
}

void solve() {
    
    int n;cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>color[i];
    }
    for(int i = 0;i < n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

signed main() {

    fastIO;
    solve();
}