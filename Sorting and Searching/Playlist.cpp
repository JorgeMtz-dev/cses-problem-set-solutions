//Author: 
#include <bits/stdc++.h>
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

void show(vector<int>&arr){
  for(auto x : arr){
      cout<< x <<' ';
  }
  cout << endl;
}

void solve() {
    
    int n;cin>>n;
    map<int,int>mapa;
    map<int,int>ok;
    vector<int>a(n,0);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    int pos = 0;
    deque<int>dq;
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(ok[a[i]] == false){
            dq.push_back(a[i]);
            ans = max(ans,SZ(dq));
            ok[a[i]]=true;
        }else{
            while(dq.front() != a[i]){
                ok[dq.front()]=false;
                dq.pop_front();
            }
            dq.pop_front();
            dq.push_back(a[i]);
        }
    }
    cout<<ans<<endl;

}

int main() {

    fastIO;
    solve();
}