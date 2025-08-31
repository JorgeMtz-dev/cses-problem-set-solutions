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

void show(vector<string>&arr){
    for(int i = 0;i < SZ(arr);i++){
        cout<<arr[i]<<endl;
    }
    cout << endl;
}
vector<string>a;
string op = "ABCD";
int n,m;

void solve() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<string> res = a; 
    for(int i = 0;i < n;i++){
        res[i] = string(SZ(a[i]),' ');
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (char c : op) {
                if (c == a[i][j]) continue;

                bool ok = true;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                        if (res[ni][nj] == c) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok) {
                    res[i][j] = c;
                    break;
                }
            }
        }
    }

    show(res);
}


signed main() {

    fastIO;
    solve();
}