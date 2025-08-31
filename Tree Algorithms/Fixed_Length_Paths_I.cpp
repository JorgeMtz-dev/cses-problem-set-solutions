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

int n,k;
vector<int>adj[MAXN];
int hijos[MAXN];
bool taken[MAXN];
int freq[MAXN];
int last_seen[MAXN];
int cur_time = 1;
ll ans = 0;

void dfs(int curr,int p){
    hijos[curr]=1;
    for(auto next : adj[curr]){
        if(next == p || taken[next])continue;
        dfs(next,curr);
        hijos[curr] += hijos[next];
    }
}

int findCentroid(int curr,int p,int sz){
    for(auto next : adj[curr]){
        if(next == p || taken[next])continue;
        if(hijos[next] > sz/2)
            return findCentroid(next,curr,sz);        
    }
    return curr;
}

void dfs_count(int curr,int p,int d,vector<int>&dist){
    if(d > k)return;
    dist.push_back(d);
    for(auto next : adj[curr]){
        if(next == p || taken[next])continue;
        dfs_count(next,curr,d+1,dist);
    }
}

void calc(int curr){
    dfs(curr,-1);
    int centroid = findCentroid(curr,-1,hijos[curr]);
    taken[centroid] = true;

    cur_time++; 
    last_seen[0] = cur_time;
    freq[0] = 1;

    vector<int>dist;
    for(auto next : adj[centroid]){
        if(taken[next])continue;
        dist.clear();
        dfs_count(next,centroid,1,dist);
        for(auto d : dist){
            if(k - d >= 0 && last_seen[k - d] == cur_time){
                ans += freq[k - d];
            }
        }
        for(auto d : dist){
            if(last_seen[d] != cur_time){
                last_seen[d] = cur_time;
                freq[d] = 0;
            }
            freq[d]++;
        }
    }

    for(auto next : adj[centroid]){
        if(taken[next])continue;
        calc(next);
    }
}

void solve() {
    cin>>n>>k;
    for(int i = 0; i < n-1; i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    calc(1);
    cout<<ans<<endl;
}

signed main() {
    fastIO;
    solve();
}
