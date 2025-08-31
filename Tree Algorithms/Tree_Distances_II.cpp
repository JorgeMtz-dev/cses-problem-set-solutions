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

int children[MAXN];
int distances[MAXN];
int ans[MAXN];

pair<int,int> dfs(int curr,int p,vector<vector<int>>&tree){
    
    for(auto next : tree[curr]){
        if(next == p)continue;

        auto [hijos,dist] = dfs(next,curr,tree);
        distances[curr] += dist;
        children[curr] += hijos;        
    }
    return {children[curr]+1,distances[curr]+children[curr]+1};
}

void reRooting(int curr,int p,vector<vector<int>>&tree){

    for(auto next : tree[curr]){
        if(next == p)continue;

        int dist = distances[next];
        int child = children[next];
       
        distances[next] += distances[curr]-(distances[next] + children[next] + 1) + children[curr]-(children[next]+1)+1;
        
        children[next] = children[curr];

        ans[next] = distances[next];
                
        reRooting(next,curr,tree);
        
        children[next] =  child;
        distances[next] = dist;

    }

}

void solve() {
    
    int n;cin>>n;
    vector<vector<int>>tree(n,vector<int>());

    for(int i = 1;i < n;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0,-1,tree);
    
    ans[0] = distances[0];
    reRooting(0,-1,tree);

    for(int i = 0;i < n;i++){
        cout<<ans[i]<<" ";
    }
}

signed main() {

    fastIO;
    solve();
}