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

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * node, l, mid);
        build(arr, 2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node, l, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Encuentra el índice del k-ésimo 1 (0-indexed). Retorna -1 si no existe.
    int kth_one(int k, int node, int l, int r) {
        if (tree[node] < k) return -1; // No hay suficientes 1s

        if (l == r) return l;

        int mid = (l + r) / 2;
        if (tree[2 * node] >= k)
            return kth_one(k, 2 * node, l, mid);
        else
            return kth_one(k - tree[2 * node], 2 * node + 1, mid + 1, r);
    }

    // Interfaces públicas
    void update(int idx, int val) {
        update(idx, val, 1, 0, n - 1);
    }

    int kth_one(int k) {
        return kth_one(k, 1, 0, n - 1);
    }
};

void solve() {
    
    int n,k;
    cin>>n;
    
    vector<int>a,arr;
    for(int i = 1;i <= n;i++){
        a.push_back(i);
        arr.push_back(1);
    }

    SegmentTree st(arr);

    int pos = 0;
    int tam = n;

    while(tam > 0){
        pos ++;
        pos %= tam;
        
        int ans = st.kth_one(pos+1);
        cout<<a[ans]<<" ";
        st.update(ans,0);
        tam--;
        
    }
    
 
}
 
int main() {
 
    fastIO;
    solve();
}