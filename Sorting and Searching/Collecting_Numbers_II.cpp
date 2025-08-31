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
int n;
void modify(int x,int &ans,int r,vector<pair<bool,int>>&a){

    if(a[x-1].first == true && a[x-1].second < r){
        a[x-1].first = false;
        ans--;
    }
    if(x < n && a[x+1].second > r && a[x].first == true){
        a[x].first = false;
        ans--;
    }

}

void solve() {
    
    int m;cin>>n>>m;
    vector<pair<bool,int>>a(n+1,{false,0});
    vector<int>xd(n+1,-1);
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int x;cin>>x;
        xd[i] = x;
        if(a[x-1].first){
            a[x-1].first = false;
        }else{
            ans++;
        }
        a[x].first = true;
        a[x].second = i;
        
    }
   
    
    for(int i = 0;i < m;i++){
        
        int l,r;cin>>l>>r;
        if(l == r){
            cout<<ans<<endl;
            continue;
        }
        int x = xd[l];
        int y = xd[r];
       
        swap(xd[l],xd[r]);
 
        if(x != 1 && a[x-1].first == false && x-1 != y){
            a[x-1].first = true;
            ans++;
        }
        if(a[x].first == false){
            ans++;
        }
        
        if(y != 1 && a[y-1].first == false && y-1 != x){
            a[y-1].first = true;
            ans++;
        }
        if(a[y].first == false){
            ans++;
            
        }
    
        a[x] = {true,r};
        a[y] = {true,l};

       // modify(x-1,ans,a[x-1].second,a);
        modify(x,ans,r,a);
       // modify(y-1,ans,a[y-1].second,a);
        modify(y,ans,l,a);


        cout<<ans<<endl;
    }
    
}

int main() {

    fastIO;
    solve();
}