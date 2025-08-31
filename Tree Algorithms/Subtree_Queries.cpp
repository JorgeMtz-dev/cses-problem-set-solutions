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

vector<int>adj[MAXN];
int in[MAXN],out[MAXN];
int t = 0;

#define NEUT 0
#define oper(a, b) (a + b)
template <class T>
class SegmentTree {
    private:
    int len;
    vector<T> ST;

public:
    SegmentTree(int len) : len(len), ST(len * 2) {}
    SegmentTree(vector<T>& v) : SegmentTree(v.size()) {
    for (int i = 0; i < len; i++)
      set(i, v[i]);
    }

void set(int ind, T val) {
    ind += len;
    ST[ind] = val;
    for (; ind > 1; ind /= 2)
        ST[ind / 2] = oper(ST[ind], ST[ind ^ 1]);
}

// [start, end]
T query(int start, int end) {
    end++;
    T ans = NEUT;
    for (start += len, end += len; start < end; start /= 2, end /= 2) {
        if (start % 2 == 1) {
            ans = oper(ans, ST[start++]);
        }
        if (end % 2 == 1) {
            ans = oper(ans, ST[--end]);
        }
    }
    return ans;
    }
};

void dfs(int curr,int p){

    in[curr]=t++;

    for(auto next : adj[curr]){

        if(next == p)continue;

        dfs(next,curr);

    }

    out[curr]=t;

}

void solve() {
    
    int n,q;cin>>n>>q;
    vector<int>a(n,0),aux(n,0);
    for(auto &x : a)cin>>x;

    for(int i = 0;i < n-1;i++){
        int u, v;cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0,-1);
    /*for(int i = 0;i < n;i++){
        cout<<in[i]<<" "<<out[i]<<endl;
    }
    cout<<endl;
    */
    for(int i = 0;i < n;i++){
        aux[in[i]] = a[i];
    }
    SegmentTree st(aux);

    for(int i = 0;i < q;i++){

        int op;cin>>op;

        if(op == 1){
            int u,x;cin>>u>>x;
            st.set(in[u-1],x);
        }else{
            int u;cin>>u;
            cout<<st.query(in[u-1],out[u-1]-1)<<endl;
        }

    }


}

signed main() {

    fastIO;
    solve();
}