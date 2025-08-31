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
    
    int n,m;
    cin>>n>>m;
    set<int>s;
    multiset<int>ms;
    s.insert(0);
    s.insert(n);
    ms.insert(n);
    for(int i = 0;i < m;i++){
        
        int x;cin>>x;
        auto it = s.lower_bound(x);
        auto it2 = it;
        it--;

        ms.erase(ms.find(*it2-*it));
        ms.insert(*it2-x);
        ms.insert(x-*it);
        cout<<(*--ms.end())<<" ";
        s.insert(x);

    }

}

int main() {

    fastIO;
    solve();
}