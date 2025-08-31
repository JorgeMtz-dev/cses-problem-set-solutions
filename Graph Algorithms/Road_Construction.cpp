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

struct DSU {
    vector<int> e;
    void init(int n) { e = vector<int>(n, -1); }
    int size(int x) { return -e[get(x)]; }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool join(int a, int b) {
        a = get(a), b = get(b);
        if (a == b)
            return false;
        if (e[a] > e[b])
            swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

void solve() {
    int n,m;cin>>n>>m;
    DSU dsu;
    dsu.init(n+1);
    int maxi = 0;
    int groups = n;
    for(int i = 0;i < m;i++){
        int u,v;cin>>u>>v;
        if(dsu.join(u,v))groups--;
        int x = dsu.size(u);
        maxi = max(x,maxi);
        cout<<groups<<' '<<maxi<<endl;
    }
}

signed main() {

    fastIO;
    solve();
}