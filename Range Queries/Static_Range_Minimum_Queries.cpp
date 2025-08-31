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

#define NEUT INT_MAX
#define oper(a, b) (min(a,b))
template <class T>
class SegmentTree {
    private:
    int len;
    vector<T> ST;

public:
    SegmentTree(int len) : len(len), ST(len * 2) {}
    SegmentTree(vector<T>& v) : SegmentTree(v.size()) {
    for (int i = 0; i < len; i++)
      set(i, v[i]);
    }

void set(int ind, T val) {
    ind += len;
    ST[ind] = val;
    for (; ind > 1; ind /= 2)
        ST[ind / 2] = oper(ST[ind], ST[ind ^ 1]);
}

// [start, end]
T query(int start, int end) {
    end++;
    T ans = NEUT;
    for (start += len, end += len; start < end; start /= 2, end /= 2) {
        if (start % 2 == 1) {
            ans = oper(ans, ST[start++]);
        }
        if (end % 2 == 1) {
            ans = oper(ans, ST[--end]);
        }
    }
    return ans;
    }
};

void solve() {

    int n,q;cin>>n>>q;
    vector<int>a(n,0);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    
    SegmentTree <int> st(a);

    while(q--){
        int l,r;cin>>l>>r;
        cout<<st.query(l-1,r-1)<<endl;
    }
    
}

signed main() {

    fastIO;
    solve();
}