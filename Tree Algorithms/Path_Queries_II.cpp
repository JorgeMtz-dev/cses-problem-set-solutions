//Author: 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
 
const int NEUTRO = 0; // Cambia según operación
 
int combine(int a, int b) {
    return max(a,b); // Cambia: max(a, b), min(a, b), __gcd(a, b), etc.
}
// --------------------------------
 
vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN];
int head[MAXN], pos[MAXN], sz[MAXN];
int valor[MAXN];
int baseVal[MAXN]; // Valor de cada nodo (original)
int cur_pos = 0;
 
// Segment Tree normal
int seg[4 * MAXN];
 
void build(int v = 1, int l = 0, int r = MAXN - 1) {
    if (l == r) {
        seg[v] = baseVal[l];
    } else {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        seg[v] = combine(seg[2 * v], seg[2 * v + 1]);
    }
}
 
void update(int idx, int value, int v = 1, int l = 0, int r = MAXN - 1) {
    if (l == r) {
        seg[v] = value;
    } else {
        int m = (l + r) / 2;
        if (idx <= m)
            update(idx, value, 2 * v, l, m);
        else
            update(idx, value, 2 * v + 1, m + 1, r);
        seg[v] = combine(seg[2 * v], seg[2 * v + 1]);
    }
}
 
int query(int ql, int qr, int v = 1, int l = 0, int r = MAXN - 1) {
    if (qr < l || ql > r) return NEUTRO;
    if (ql <= l && r <= qr) return seg[v];
    int m = (l + r) / 2;
    return combine(query(ql, qr, 2 * v, l, m), query(ql, qr, 2 * v + 1, m + 1, r));
}
 
// Heavy-Light Decomposition
int dfs(int v, int p) {
    parent[v] = p;
    sz[v] = 1;
    int max_sz = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        int sz_u = dfs(u, v);
        sz[v] += sz_u;
        if (sz_u > max_sz) {
            max_sz = sz_u;
            heavy[v] = u;
        }
    }
    return sz[v];
}
 
void decompose(int v, int h) {
    head[v] = h;
    baseVal[cur_pos] = valor[v];
    pos[v] = cur_pos++;
 
    //baseVal[pos[v]] = baseVal[v]; // mover valor real al arreglo plano
 
    if (heavy[v] != -1) decompose(heavy[v], h);
    for (int u : adj[v]) {
        if (u != parent[v] && u != heavy[v]) {
            decompose(u, u); // inicia nueva cadena
        }
    }
}
 
// Consulta en el camino u-v
int query_path(int u, int v) {
    int res = NEUTRO;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        int top = head[u];
        res = combine(res, query(pos[top], pos[u]));
        u = parent[top];
    }
    //
    if (depth[u] > depth[v]) swap(u, v);
    res = combine(res, query(pos[u], pos[v]));
    return res;
}
// Actualiza el valor de un nodo
void update_node(int u, int new_val) {
    valor[u]=new_val;
    update(pos[u], new_val);
}
 
void solve() {
    
    int n,q;cin>>n>>q;
    memset(heavy, -1, sizeof heavy);
    for(int i = 0;i < n;i++){
        cin>>valor[i];
    }
    for(int i = 0;i < n-1;i++){
        int u , v;cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);         
    decompose(0, 0);    
    build();            
    string xd = "";
    for(int i = 0;i < q;i++){
        int op;cin>>op;
        if(op == 1){
 
            int u,x;cin>>u>>x;
            u--;
            update_node(u, x);
 
        }else{
            int u,v;cin>>u>>v;
            u--;v--;
            xd += to_string(query_path(u, v)) + " ";
        }
    }
    cout<<xd<<endl;
 
}
 
signed main() {
 
    fastIO;
    solve();
}