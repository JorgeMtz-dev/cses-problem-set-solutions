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
typedef priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqg; ///Min
typedef priority_queue<int> pq; ///Max
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void show(vector<int>&arr){
  for(auto x : arr){
      cout<< x <<' ';
  }
  cout << endl;
}
bool used[MAXN];
vector<pair<int,int>>adj[MAXN];
int n,m,k;
pq ans[MAXN];
pqg q;

void solve() {
    
    cin>>n>>m>>k;
    for(int i = 0;i < m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
    }
    ans[1].push(0);
    q.emplace(0,1);
    while(!q.empty()){

        auto [sum,curr] = q.top();
        q.pop();
        //si la suma es mayor que la distancia mayor de curr
        if(sum > ans[curr].top())continue;

        for(auto [next,w] : adj[curr]){
            int sum2 = w+sum;
            if(SZ(ans[next]) < k){
                ans[next].push(sum2);
                q.emplace(sum2,next);
            }else if(sum2 < ans[next].top()){
                ans[next].pop();
                ans[next].push(sum2);
                q.emplace(sum2,next);
            }
        }

    }
    vector<int>print;
    while(!ans[n].empty()){
        print.push_back(ans[n].top());
        ans[n].pop();
    }
    sort(all(print));
    show(print);


}

signed main() {

    fastIO;
    solve();
}