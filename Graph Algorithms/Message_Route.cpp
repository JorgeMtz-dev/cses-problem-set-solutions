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

void bfs(int curr,vector<bool>&visited,vector<vector<int>>&grafo,vector<int>&padres){

    queue<int>q;
    q.push(curr);
    visited[curr] = true;
    while(!q.empty()){

        curr = q.front();
        q.pop();

        for(auto next : grafo[curr]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                padres[next] = curr;
            }
        }

    }

}

vector<int> reconstructPath(int curr,vector<int>&padres){
    vector<int>path;
    while(padres[curr] != -1){
        path.push_back(curr);
        curr = padres[curr];
    }
    path.push_back(curr);
    reverse(all(path));
    return path;
}

void solve() {
    
    int n,m;cin>>n>>m;
    vector<vector<int>>grafo(n,vector<int>());
    vector<int>padres(n,-1);
    vector<bool>visited(n,false);
    for(int i = 0;i < m;i++){
        int x,y;cin>>x>>y;
        x--;y--;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }

    bfs(0,visited,grafo,padres);

    if(!visited[n-1]){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        auto ans = reconstructPath(n-1,padres);
        cout<<SZ(ans)<<endl;
        for(auto x : ans){
            cout<<x+1<<" ";
        }
        cout<<endl;
    }

}

int main() {

    fastIO;
    solve();
}