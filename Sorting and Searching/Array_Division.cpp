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
typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void show(vector<int>&arr){
  for(auto x : arr){
      cout<< x <<' ';
  }
  cout << endl;
}

int a[MAXN];
int n,k;

bool check(int mid){

    int cnt = 1;
    int sum = 0;
    //2 4 7 3 5
    for(int i = 0;i < n;i++){
        if(a[i] > mid)return false;
        if(sum + a[i] <= mid){
            sum+=a[i];
        }else{
            sum = a[i];
            cnt++;
        }
    }
    return cnt <= k;
}

void solve() {
    
    cin>>n>>k;
    int high = 0;
    int low = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        high+=a[i];
    }

    while(high-low > 1){
        int mid = (high+low)/2;

        if(check(mid)){
            high = mid;
        }else{
            low = mid;
        }
    }
    cout<<high<<endl;
}

signed main() {

    fastIO;
    solve();
}