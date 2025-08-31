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
 
struct FenwickRangeUpdate {
    int n;
    vector<ll> bit1, bit2;
    FenwickRangeUpdate(int n): n(n), bit1(n+1), bit2(n+1) {}
    
    void add(vector<ll> &bit, int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    
    ll sum(const vector<ll> &bit, int idx) {
        ll ret = 0;
        for (; idx > 0; idx -= idx & -idx) ret += bit[idx];
        return ret;
    }
    
    void range_add(int l, int r, ll val) {
        add(bit1, l, val);
        add(bit1, r+1, -val);
        add(bit2, l, val*(l-1));
        add(bit2, r+1, -val*r);
    }
    
    ll prefix_sum(int x) {
        return sum(bit1, x)*x - sum(bit2, x);
    }
    
    ll point_query(int x) {
        return prefix_sum(x) - prefix_sum(x-1);
    }
};
 
struct HLD {
    int n;
    vector<vector<int>> &g;
    vector<int> parent;
    vector<int> jump;
    vector<int> total;
    vector<int> order;
 
    HLD(vector<vector<int>> &g) : n(g.size()), g(g), parent(n), jump(n), total(n), order(n) {
        dfs_size(0);
        int order_index = 0;
        dfs_hld(0, order_index);
    }
 
    template <typename F>
    
    void path_query(int a, int b, F f) {
        for (;; a = parent[jump[a]]) {
            if (order[a] < order[b]) swap(a, b);
            if (order[jump[a]] <= order[b]) {
                f(order[b]+1, order[a]+1);
                return;
            }
            f(order[jump[a]]+1, order[a]+1);
        }
    }
	//primera aparicion del nodo x
    int position(int x) { return order[x]; }
    pair<int, int> subtree(int x) {
        return {order[x], order[x] + total[x] - 1};
    }
 
private:
    void dfs_size(int node) {
        total[node] = 1;
        for (auto &child : g[node]) {
            g[child].erase(find(g[child].begin(), g[child].end(), node));
            dfs_size(child);
            total[node] += total[child];
            if (total[child] > total[g[node][0]]) {
                swap(child, g[node][0]);
            }
        }
    }
 
    void dfs_hld(int node, int &order_index) {
        order[node] = order_index++;
        for (auto child : g[node]) {
            parent[child] = node;
            if (child == g[node][0]) {
                jump[child] = jump[node];
            } else {
                jump[child] = child;
            }
            dfs_hld(child, order_index);
        }
    }
};
 
 
void solve() {
    int n,q;cin>>n>>q;
    vector<vector<int>>adj(n);
    for(int i = 0;i < n-1;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    HLD hld(adj);
    
    FenwickRangeUpdate lst(n+1);
 
    for(int i = 0;i < q;i++){
 
        int u,v;cin>>u>>v;
        u--;v--;
        hld.path_query(u, v, [&](int l, int r){
            lst.range_add(l, r, 1);
        });
    }
    for(int i = 0;i < n;i++){
        cout << lst.point_query(hld.position(i)+1) << " ";
    }
 
    
    
}
 
int main() {
 
    fastIO;
    solve();
}