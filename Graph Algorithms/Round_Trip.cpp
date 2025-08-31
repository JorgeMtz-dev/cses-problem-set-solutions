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
const int blanco = 0,gris = 1,negro = 2;
void show(vector<int>&arr){
  for(auto x : arr){
      cout<< x+1 <<' ';
  }
  cout << endl;
}
int ini = -1;

vector<int>recoverPath(vector<int>&padres){
    vector<int>path;
    int aux = ini;
    path.push_back(aux);
    aux = padres[aux];
    while(aux != ini){
        path.push_back(aux);
        aux = padres[aux];
    }
    return path;
}

void dfs(int curr,int tam,vector<int>&padres,vector<int>&visited,vector<vector<int>>&grafo){
    if(ini != -1)return;
    for(auto next : grafo[curr]){
        if(ini != -1)return;
        if(visited[next] == blanco){
            visited[next] = gris;
            padres[next] = curr;
            dfs(next,tam+1,padres,visited,grafo);
            //visited[next] = negro;
        }else if(visited[next] == gris && padres[curr] != next){
            //ciclo
            if(tam >= 3){
                ini = next;
                padres[next] = curr;
            }
        }
    }

}

void solve() {
    
    int n,m;cin>>n>>m;
    vector<vector<int>>grafo(n,vector<int>());
    vector<int>padres(n,-1);
    vector<int>visited(n,blanco);

    for(int i = 0;i < m;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
   
    for(int i = 0;i < n;i++){
        if(visited[i] == blanco && ini == -1){
            visited[i] = gris;
            dfs(i,1,padres,visited,grafo);
           // visited[i] = negro;
        }
    }
   
    if(ini == -1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    
    auto ans = recoverPath(padres);
    cout<<SZ(ans)+1<<endl;
    for(auto x : ans)cout<<x+1<<" ";
    cout<<ini+1;
    cout<<endl;

}

int main() {

    fastIO;
    solve();
}