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

/*void dfs(int curr,vector<vector<int>>&grafo,vector<bool>&visited){

    for(auto next : grafo[curr]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next,grafo,visited);
        }
    }

}*/

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
    //vector<vector<int>>grafo(n,vector<int>());
    //vector<bool>visited(n,false);
    DSU dsu;dsu.init(n);

    for(int i = 0;i < m;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        dsu.join(x,y);
        /*grafo[x].push_back(y);
        grafo[y].push_back(x);*/
    }
    int ant = 0;
    vector<int>ans;
    for(int i = 1;i < n;i++){
        if(dsu.get(i) != dsu.get(ant)){
            dsu.join(ant,i);
            ans.push_back(i);
        }
        /*if(!visited[i]){
            visited[i] = true;
            dfs(i,grafo,visited);
            if(ant != -1){
                ans.push_back({ant,i});
            }
            ant = i;
        }*/

    }
    cout<<SZ(ans)<<endl;
    for(auto x : ans){
        cout<<1<<' '<<x+1<<endl;
    }


}

int main() {

    fastIO;
    solve();
}