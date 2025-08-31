// Author:
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define fastIO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define int long long
#define V vector
#define pb push_back
#define pf push_front
#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define all(v) v.begin(), v.end()
#define endl '\n'
#define SZ(x) (int)x.size()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define oper(a, b) (a ^ b)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
using pi = pair<int, int>;

constexpr ull MOD2 = (1ULL << 32);
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};     // abajo, derecha, arriba, izquierda
typedef priority_queue<int, vector<int>, greater<int>> pqg; /// Min
typedef priority_queue<int> pq;                             /// Max
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void show(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}


void solve()
{
    int n, k, ans = 0, L = 0, M = 0, cur = 0, R = 1;
    long long a, b, c;
    cin >> n >> k;
    vector<long long> x(n);
    vector<int> suf(n);

    cin >> x[0] >> a >> b >> c;
    for (int i = 1; i < n; i++)
    {
        x[i] = (a * x[i - 1] + b) % c;
    }

    for (int i = 0; i + k <= n; i++)
    {
        int j = i + k;
        if (i == M)
        {
            L = M;
            M = j;
            suf[M] = 0;
            for (int t = M - 1; t >= L; t--)
            {
                suf[t] = oper(suf[t + 1], x[t]);
            }
            R = M;
            cur = 0;
        }
        while (R < j)
        {
            cur = oper(cur, x[R++]);
        }
        ans ^= oper(suf[i], cur);
    }
    cout << ans << '\n';
}

signed main()
{

    solve();

    return 0;
}