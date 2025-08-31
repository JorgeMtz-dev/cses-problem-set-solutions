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
 
void solve() {
    int n;
    cin >> n;

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    vector<bool> dp(MAXN, false);
    dp[0] = true;

    for (auto [val, cnt] : freq) {

        for (int i = MAXN - 1; i >= 0; i--) {
            if (!dp[i]) continue;

            for (int k = 1; k <= cnt && i + k * val < MAXN; k++) {
                dp[i + k * val] = true;
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i < MAXN; i++) {
        if (dp[i]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    show(ans);
}

 
signed main() {
 
    fastIO;
    solve();
}