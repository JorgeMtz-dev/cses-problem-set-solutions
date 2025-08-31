//Author: 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;

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

void Insert(ordered_set &s,int x){ 
//this function inserts one more occurrence of (x) into the set.
     s.insert(x);
}
bool Exist(ordered_set &s,int x){
//this function checks weather the value (x) exists in the set or not.
     if((s.upper_bound(x))==s.end()){
        return 0;
     }
     return ((*s.upper_bound(x))==x);
}
void Erase(ordered_set &s,int x){
//this function erases one occurrence of the value (x).
     if(Exist(s,x)){
        s.erase(s.upper_bound(x));
     }
}

int Value(ordered_set &s,int idx){ 
//this function returns the value at the index (idx)..(0 indexing).
   return (*s.find_by_order(idx));
}

void solve() {
    ordered_set MoSet;
    int n,k;cin>>n>>k;
    vector<int>a(n,0);
    for(auto &x : a)cin>>x;

    for(int i = 0;i < k;i++){
        Insert(MoSet,a[i]);
    }
    if(k&1)
        cout<<Value(MoSet,SZ(MoSet)/2)<<" ";
    else
        cout<<min(Value(MoSet,SZ(MoSet)/2),Value(MoSet,SZ(MoSet)/2-1))<<" ";
    
    for(int i = k;i < n;i++){
        Erase(MoSet,a[i-k]);
        Insert(MoSet,a[i]);
        //2 4 3
        if(k&1)
            cout<<Value(MoSet,SZ(MoSet)/2)<<" ";
        else
            cout<<min(Value(MoSet,SZ(MoSet)/2),Value(MoSet,SZ(MoSet)/2-1))<<" ";    
    }

}

int main() {

    fastIO;
    solve();
}