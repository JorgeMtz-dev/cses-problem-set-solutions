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
#define debug(x) cout << #x << ' ' << (x) << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
using pi = pair<int, int>;

constexpr ull MOD2 = (1ULL<<32);
constexpr int MOD = 1e9+7;
constexpr int MAXN = 1e5+5;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};  // abajo, derecha, arriba, izquierda
void show(vector<int>&arr){
  for(auto x : arr){
      cout<< x <<' ';
  }
  cout << endl;
}

void solve() {
    
    int n,a,c;cin>>n>>a>>c;
    
    if(a+c > n || (a==0) != (c==0)){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i = 0;i < n;i++)cout<<i+1<<" ";
    cout<<endl;
    int i = 1;
    while(a>=2 && c>=2){
        a--;
        c--;
        cout<<i+1<<" "<<i<<" ";
        i+=2;
    }

    int k = max(a,c);
    //1 2 3 4 5
    //5 1 2 3 4
    //2 3 4 5 1
    if(a == 1 || c == 1){
        if(c >= a){
            for(int j = i+1;j <= i+k;j++)cout<<j<<" ";
            cout<<i<<" ";
        }else{
            cout<<i+k<<" ";
            for(int j = i;j < i+k;j++)cout<<j<<" ";
        }
    }
    if(k == 0)i--;
    for(int j = i+k+1;j <= n;j++){
        cout<<j<<" ";
    }
    cout<<endl;

}

int main() {

    fastIO;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}