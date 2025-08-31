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
constexpr int MAXN = 2e5+5;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};  // abajo, derecha, arriba, izquierda
typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void show(deque<int>&arr){
  for(auto x : arr){
      cout<< x <<' ';
  }
  cout << endl;
}



int p[MAXN];

void bellmanFord(vector<tuple<int,int,int>>& e, int n,int x) {
    const int INF = 1e9;

    vi d(n, INF); d[x] = 0;
    for (int i=0;i<n;i++)
        for(auto& [u, v, w]:e){
            if(d[v] > d[u]+w){
                d[v] = d[u]+w;
                p[v]=u;
                //d[v]=min(d[v],d[u]+w);
            }
        }

    int y = -1;
    for(auto& [u, v, w]:e)
        if(d[u]!=INF&&d[u]+w<d[v]) {
            y = u;
            break;
        // neg cycle: all nodes reachable from u have -INF distance. To reconstruct
        // neg cycle save "prev" of each node, go up from u until repeating a node.
        // this node and all nodes between the two occurences form a neg cycle
        }
    if(y == -1){
        cout<<"NO"<<endl;
        return;
    }
    deque<int>path;
    vector<bool>ok(n,false);
    while(!ok[y]){
        ok[y]=true;
        path.push_back(y);
        y = p[y];
    }
    while(path.front()!=y)path.pop_front();
    path.push_back(y);
    
    cout<<"YES"<<endl; 
    reverse(all(path));
    show(path);
}

void solve() {

    int n,m;cin>>n>>m;
    vector<tuple<int,int,int>>g;
    for(int i = 0;i < m;i++){
        int u,v,w;cin>>u>>v>>w;
        g.emplace_back(u,v,w);
    }
    bellmanFord(g, n+1, 1);
    
}

signed main() {

    fastIO;
    solve();
}