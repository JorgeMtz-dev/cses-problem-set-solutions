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

void solve() {
    
    int n,k;cin>>n>>k;
    vector<int>a(n,0);
    vector<int>b(k+1,-1);
    b[0] = 1;
    for(auto &x : a)cin>>x;

    for(int i = 0;i <= k;i++){
        if(b[i] != -1)
            for(auto x : a){
                if(i+x <= k){
                    if(b[i+x] == -1)b[i+x]=0;
                    b[i+x] += b[i];
                    b[i+x]%=MOD;
                }
            }
    }
    if(b[k] == -1)b[k]=0;
    cout<<b[k]<<endl;

}

int main() {

    fastIO;
    solve();
}