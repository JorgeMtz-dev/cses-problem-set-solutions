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
        const T neutral = 0;  // cambiar según la operación
        vector<T> st, lazyAdd, lazySet;
        vector<bool> isSet; // indica si hay una asignación pendiente

        inline int l(int p) { return (p << 1) + 1; }
        inline int r(int p) { return (p << 1) + 2; }

        // operación de combinación
        T merge(T a, T b) {
            return a + b;
        }

        void applySet(int index, int start, int end, T val) {
            st[index] = (end - start + 1) * val;
            lazySet[index] = val;
            isSet[index] = true;
            lazyAdd[index] = 0;  // cancelar cualquier suma pendiente
        }

        void applyAdd(int index, int start, int end, T val) {
            if (isSet[index]) {
                // si ya hay una asignación, sumamos sobre el valor asignado
                lazySet[index] += val;
            } else {
                lazyAdd[index] += val;
            }
            st[index] += (end - start + 1) * val;
        }

        void push(int index, int start, int end) {
            if (isSet[index]) {
                int m = (start + end) / 2;
                applySet(l(index), start, m, lazySet[index]);
                applySet(r(index), m + 1, end, lazySet[index]);
                isSet[index] = false;
            }
            if (lazyAdd[index]) {
                int m = (start + end) / 2;
                applyAdd(l(index), start, m, lazyAdd[index]);
                applyAdd(r(index), m + 1, end, lazyAdd[index]);
                lazyAdd[index] = 0;
            }
        }

        void add(int index, int start, int end, int i, int j, T val) {
            if (j < start || end < i) return;
            if (i <= start && end <= j) {
                applyAdd(index, start, end, val);
                return;
            }
            push(index, start, end);
            int mid = (start + end) / 2;
            add(l(index), start, mid, i, j, val);
            add(r(index), mid + 1, end, i, j, val);
            st[index] = merge(st[l(index)], st[r(index)]);
        }

        void assign(int index, int start, int end, int i, int j, T val) {
            if (j < start || end < i) return;
            if (i <= start && end <= j) {
                applySet(index, start, end, val);
                return;
            }
            push(index, start, end);
            int mid = (start + end) / 2;
            assign(l(index), start, mid, i, j, val);
            assign(r(index), mid + 1, end, i, j, val);
            st[index] = merge(st[l(index)], st[r(index)]);
        }

        T query(int index, int start, int end, int i, int j) {
            if (j < start || end < i) return neutral;
            if (i <= start && end <= j) return st[index];
            push(index, start, end);
            int mid = (start + end) / 2;
            return merge(
                query(l(index), start, mid, i, j),
                query(r(index), mid + 1, end, i, j)
            );
        }

    public:
        LazySegmentTree(int sz)
            : n(sz), st(4 * n), lazyAdd(4 * n), lazySet(4 * n), isSet(4 * n, false) {}

        void add(int i, int j, T val) { add(0, 0, n - 1, i, j, val); }
        void assign(int i, int j, T val) { assign(0, 0, n - 1, i, j, val); }
        T query(int i, int j) { return query(0, 0, n - 1, i, j); }
};


void solve() {

    int n,q;cin>>n>>q;
    LazySegmentTree<int>lst(n);
    for(int i = 0;i < n;i++){
        int x;cin>>x;
        lst.assign(i,i,x);
    }
    for(int i = 0;i < q;i++){
        int op;cin>>op;
        int l,r;cin>>l>>r;
        l--,r--;
        if(op == 1){
            //add
            int x;cin>>x;
            lst.add(l,r,x);
        }else if(op == 2){
            //set
            int x;cin>>x;
            lst.assign(l,r,x);
        }else{
            //sum
            cout<<lst.query(l,r)<<endl;
        }
    }
    
}

signed main() {

    fastIO;
    solve();
}