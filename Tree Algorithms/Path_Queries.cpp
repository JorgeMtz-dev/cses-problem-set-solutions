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

#define NEUT 0
#define oper(a, b) (a + b)
template <class T>
class SegmentTree {
    private:
    vector<T> ST;
    int len;

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

int in[MAXN];
int out[MAXN];
int tiempo = 0;

void dfs(int curr,int p,const vector<vector<int>>&grafo,const vector<int>&costos,vector<int>&vTree){

    in[curr] = tiempo++;
    vTree.push_back(costos[curr]);
    for(auto next : grafo[curr]){

        if(next == p)continue;

        dfs(next,curr,grafo,costos,vTree);

    }
    out[curr] = tiempo++;
    vTree.push_back(-costos[curr]);

}

void solve() {
    
    int n,q;cin>>n>>q;
    vector<int>costos(n,0);
    vector<vector<int>>grafo(n,vector<int>());
    vector<int>vTree;
    for(auto &x : costos)cin>>x;
    for(int i = 0;i < n-1;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    dfs(0,-1,grafo,costos,vTree);
    SegmentTree st(vTree);

    for(int i = 0;i < q;i++){
        //queries
        int op;cin>>op;
        int u;cin>>u;
        u--;

        if(op == 2){
            cout<<st.query( in[0] , in[u] )<<endl;
        }else{
            int val;cin>>val;
            st.set(in[u],val);
            st.set(out[u],-val);
        }
    }


}

signed main() {

    fastIO;
    solve();
}