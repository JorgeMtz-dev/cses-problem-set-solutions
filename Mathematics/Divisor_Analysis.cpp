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

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res%MOD;
}
ll modinv(ll a) {
    return binpow(a, MOD - 2); 
}

void solve() {
    
    ll n;cin>>n;
    ll N = 1;
    ll cntFactors = 1;
    ll sumDivisors = 1;
    ll productDivisors = 1;
    ll fermat = 1;
    vector<pair<int,int>>entrada;
    for(int i = 0;i < n;i++){
        ll factor,exp;cin>>factor>>exp;
        entrada.emplace_back(factor,exp);
        cntFactors *= (exp+1LL);
        sumDivisors *= ((binpow(factor,exp+1)-1LL+MOD)%MOD) * modinv(factor-1)%MOD;
        productDivisors = binpow(productDivisors,exp+1)*binpow(binpow(factor,exp*(exp+1)/2),fermat);
        fermat *= (exp+1LL);

        cntFactors %= MOD;
        sumDivisors %= MOD;
        productDivisors %= MOD;
        fermat %= (MOD-1);
    }

    cout<<cntFactors<<' '<<sumDivisors<<' '<<productDivisors<<endl;

}

signed main() {

    fastIO;
    solve();
}