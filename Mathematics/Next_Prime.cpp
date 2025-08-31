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
#define debug(x) cout << #x << ' ' << (x) << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
using pi = pair<int, int>;

constexpr ull MOD2 = (1ULL<<32);
constexpr int MOD = 1e9+7;
constexpr int MAXN = 2e5+5;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};  // abajo, derecha, arriba, izquierda
void show(vector<int>&arr){
  for(auto x : arr){
      cout<< x <<' ';
  }
  cout << endl;
}
using u64 = uint64_t;
using u128 = __uint128_t;

// Fast modular exponentiation
u64 modpow(u64 a, u64 d, u64 mod) {
    u128 res = 1, base = a % mod;
    while (d > 0) {
        if (d & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        d >>= 1;
    }
    return (u64)res;
}

// Miller–Rabin primality test (deterministic for n < 2^64)
bool isPrime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (n % p == 0) return n == p;
    }
    u64 d = n - 1, s = 0;
    while ((d & 1) == 0) { d >>= 1; s++; }
    auto check = [&](u64 a)->bool {
        if (a % n == 0) return true;
        u64 x = modpow(a, d, n);
        if (x == 1 || x == n - 1) return true;
        for (u64 r = 1; r < s; r++) {
            x = (u128)x * x % n;
            if (x == n - 1) return true;
        }
        return false;
    };
    for (u64 a : {2,3,5,7,11}) {
        if (!check(a)) return false;
    }
    return true;
}

// Next prime after N
u64 nextPrime(u64 N) {
    if (N < 2) return 2;
    u64 x = N + 1;
    if (x % 2 == 0) x++;
    while (!isPrime(x)) x += 2;
    return x;
}

// Previous prime before N
u64 prevPrime(u64 N) {
    if (N <= 2) return 0; // no hay primo menor a 2
    u64 x = N - 1;
    if (x % 2 == 0) x--;
    while (x >= 2 && !isPrime(x)) x -= 2;
    return (x >= 2 ? x : 0);
}

void solve() {
    
    u64 N;
    cin >> N;
    cout<<nextPrime(N)<<endl;
    
}

signed main() {

    fastIO;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}