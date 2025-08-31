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

vector<int> adj[MAXN];
int disc[MAXN], low[MAXN], timer;
bool inStack[MAXN];
stack<int> stk;
vector<vector<int>> sccs;

void tarjanDFS(int u) {
    disc[u] = low[u] = timer++;
    stk.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            tarjanDFS(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (disc[u] == low[u]) {
        vector<int> scc;
        int v;
        do {
            v = stk.top(); stk.pop();
            inStack[v] = false;
            scc.push_back(v);
        } while (v != u);
        sccs.push_back(scc);
    }
}

void tarjanSCC(int n) {
    timer = 0;
    fill(disc, disc + n, -1);
    fill(low, low + n, -1);
    fill(inStack, inStack + n, false);

    for (int i = 0; i < n; ++i) {
        if (disc[i] == -1)
            tarjanDFS(i);
    }
}

void solve() {
    
    int n,m;cin>>n>>m;
    for(int i = 0;i < m;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
    }
    tarjanSCC(n);
    vector<int>ans(n,0);
    int cnt = 1;
    for(auto v : sccs){
        for(auto x : v){
            ans[x]=cnt;
        }
        cnt++;
    }
    cout<<SZ(sccs)<<endl;
    show(ans);

}

int main() {

    fastIO;
    solve();
}