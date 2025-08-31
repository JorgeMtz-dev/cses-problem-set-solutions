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
int FirstIdx(ordered_set &s,int x){ 
//this function returns the first index of the value (x)..(0 indexing).
    if(!Exist(s,x)){
        return -1;
    }
    return (s.order_of_key(x));
}
int Value(ordered_set &s,int idx){ 
//this function returns the value at the index (idx)..(0 indexing).
   return (*s.find_by_order(idx));
}
int LastIdx(ordered_set &s,int x){ 
//this function returns the last index of the value (x)..(0 indexing).
    if(!Exist(s,x)){
        return -1;
    }
    if(Value(s,(int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return FirstIdx(s,*s.lower_bound(x))-1;
}
int Count(ordered_set &s,int x){ 
//this function returns the number of occurrences of the value (x).
     if(!Exist(s,x)){
        return 0;
     }
     return LastIdx(s,x)-FirstIdx(s,x)+1;
}
void Clear(ordered_set &s){ //this function clears all the elements from the set.
     s.clear();
}
int Size(ordered_set &s){ //this function returns the size of the set.
     return (int)(s.size());
}

void solve() {
    int n,q;cin>>n>>q;
    ordered_set MoSet;
    vector<int>a(n,0);
    for(int i = 0;i < n;i++){
        int x;cin>>x;
        a[i]=x;
        Insert(MoSet,x);
    }
    for(int i = 0;i < q;i++){
        char op;cin>>op;
        if(op == '?'){
            int l,r;cin>>l>>r;
            //int pos = MoSet.lower_bound(l)-MoSet.begin();
            int idxl = MoSet.order_of_key(l);
            int idxr = MoSet.order_of_key(r+1);
            idxr--;

            if(idxl > idxr)cout<<0<<endl;
            else cout<<idxr-idxl+1<<endl;

        }else{
            int k,x;cin>>k>>x;
            int xd = a[k-1];
            a[k-1]=x;
            Erase(MoSet,xd);
            Insert(MoSet,x);
            //MoSet.erase(MoSet.find(xd));
           // MoSet.insert(x);
        }
    }
}

signed main() {

    fastIO;
    solve();
}