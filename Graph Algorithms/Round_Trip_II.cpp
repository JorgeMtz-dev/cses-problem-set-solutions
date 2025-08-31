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

vector<int>adj[MAXN];
int parent[MAXN];
int color[MAXN];
int blanco = 0,gris = 1,negro = 2;
vector<int>path;

bool dfs(int curr){
    
    color[curr] = gris;
    for(auto next : adj[curr]){
        if(next == curr)continue;

        if(color[next] == blanco){
            parent[next] = curr;
            if(dfs(next))return true;
        }else if(color[next] == gris){
            //ciclo
            int x = curr;
            path.push_back(next);
            while(x != next){
                path.push_back(x);
                x = parent[x];
            }
            path.push_back(next);
            return true;
            
        }
    }
    color[curr] = negro;
    return false;
}

void solve(){
    
    int n,m;cin>>n>>m;
    for(int i = 0;i < m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i = 1;i <= n;i++){
        if(!parent[i]){
            parent[i] = -1;
            if(dfs(i))break;
        }
    }

    if(!SZ(path)){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        reverse(all(path));
        cout<<SZ(path)<<endl;
        show(path);
    }
}

signed main() {

    fastIO;
    solve();
}