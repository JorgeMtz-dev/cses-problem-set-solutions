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

template <class T>
class LazySegmentTree {
    private:
        int n;
        const T neutral = 0;  // Cambiar segun la operacion
        vector<T> A, st, lazy;

        inline int l(int p) { return (p << 1) + 1; }  // ir al hijo izquierdo
        inline int r(int p) { return (p << 1) + 2; }  // ir al hijo derecho

        // Cambiar segun la operacion
        T merge(T a, T b) {
            return a + b;
        }

        // Nota: Si se utiliza para el minimo o maximo de un rango no se le agrega el (end - start + 1)
        void propagate(int index, int start, int end, T dif) {
            st[index] += (end - start + 1) * dif;
            if (start != end) {
                lazy[l(index)] += dif;
                lazy[r(index)] += dif;
            }
            lazy[index] = 0;
        }

        void add(int index, int start, int end, int i, int j, T val) {
            if (lazy[index]) {
                propagate(index, start, end, lazy[index]);
            }

            if ((end < i) || (start > j))
                return;

            if (start >= i && end <= j) {
                propagate(index, start, end, val);
                return;
            }
            int mid = (start + end) / 2;

            add(l(index), start, mid, i, j, val);
            add(r(index), mid + 1, end, i, j, val);

            st[index] = merge(st[l(index)], st[r(index)]);
        }

        T query(int index, int start, int end, int i, int j) {
            if (lazy[index]) {
                propagate(index, start, end, lazy[index]);
            }

            if (end < i || start > j)
                return neutral;
            if ((i <= start) && (end <= j))
                return st[index];

            int mid = (start + end) / 2;

            return merge(query(l(index), start, mid, i, j), query(r(index), mid + 1, end, i, j));
        }

    public:
        LazySegmentTree(int sz) : n(sz), st(4 * n), lazy(4 * n) {}
        // [i, j]
        void add(int i, int j, T val) { add(0, 0, n - 1, i, j, val); }  // [i, j]
        T query(int i, int j) { return query(0, 0, n - 1, i, j); }      // [i, j]
};

void solve() {
  
    int n,q;cin>>n>>q;
    vector<int>a(n);
    LazySegmentTree <int> lst(n+1);
    for(int i = 0;i < n;i++){
        cin>>a[i];
        lst.add(i+1,i+1,a[i]);
    }
    while(q--){
        int op;cin>>op;
        if(op == 1){
            int l,r,val;cin>>l>>r>>val;
            lst.add(l,r,val);
        }else{
            int k;cin>>k;
            cout<<lst.query(k,k)<<endl;
        }
    }


}

signed main() {

    fastIO;
    solve();
}