// Author:
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define fastIO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
using pi = pair<int, int>;

constexpr ull MOD2 = (1ULL << 32);
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e5 + 5;

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
const int LOG = 21;

vector<int> g[MAXN];
int in[MAXN];
int t = 0;
vector<pair<int,int>>d;

void dfs(int curr, int p, int depth)
{
    
    in[curr] = SZ(d);
    d.push_back({depth,curr});
    for (auto next : g[curr])
    {
        if (next == p)
            continue;
        dfs(next, curr, depth + 1);
        d.push_back({depth,curr});
    }
    
}

template <class T>

struct SparseTable
{

    vector<vector<T>> jmp;

    void init(const vector<T> &V)
    {

        if (SZ(jmp))
            jmp.clear();

        jmp.emplace_back(V);

        for (int pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, ++k)
        {

            jmp.emplace_back(SZ(V) - pw * 2 + 1);

            FOR(j, 0, SZ(jmp[k]))
            {

                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
            }
        }
    }

    T query(int l, int r)
    { // [a, b)

        int dep = 31 - __builtin_clz(r - l);

        return min(jmp[dep][l], jmp[dep][r - (1 << dep)]);
    }
};

void solve()
{

    int n, q;
    cin >> n >> q;
    SparseTable <pair<int,int>> st;
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        g[u].push_back(i);
        g[i].push_back(u);
    }
    dfs(1, 0, 0);
    st.init(d);
    
    while(q--){

        int u,v;cin>>u>>v;
        int l = in[u];
        int r = in[v];

        if(l > r)swap(l,r);

        cout<<st.query(l,r+1).second<<endl;

    }
    
}

int main()
{

    fastIO;
    solve();
}