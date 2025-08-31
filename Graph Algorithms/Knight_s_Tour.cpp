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

const int N = 8;
int pos(int i, int j)
{
    return i * N + j;
}

bool isValid(int i, int j)
{
    return i >= 0 && i < N && j >= 0 && j < N;
}
int cnt = 1;
bool dfs(int i, int j, vector<vector<int>>& grafo, vector<vector<int>>& grid) {
    if (cnt > N * N) return true;  // Se recorrieron todas las celdas

    vector<pair<int, int>> next;

    for (auto x : grafo[pos(i, j)]) {
        int ii = x / N;
        int jj = x % N;

        if (grid[ii][jj] != 0) continue;

        int posibles = 0;
        for (auto y : grafo[x]) {
            int ni = y / N, nj = y % N;
            if (grid[ni][nj] == 0) posibles++;
        }
        next.emplace_back(posibles, x);
    }


    sort(next.begin(), next.end());

    for (auto [_, x] : next) {
        int ii = x / N;
        int jj = x % N;

        grid[ii][jj] = cnt++;
        if (dfs(ii, jj, grafo, grid)) return true;
        grid[ii][jj] = 0;
        cnt--;
    }

    return false;
}


void solve()
{
    int n, m;
    cin >> n >> m;
    n--;
    m--;

    vector<vector<int>> grid(N, vector<int>(N, 0));
    vector<vector<int>> grafo(N * N, vector<int>());
    vector<int> di = {-2, -2, 2, 2, 1, -1, 1, -1};
    vector<int> dj = {1, -1, 1, -1, -2, -2, 2, 2};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (isValid(i + di[k], j + dj[k]))
                {
                    grafo[pos(i, j)].push_back(pos(i + di[k], j + dj[k]));
                }
            }
        }
    }
    grid[m][n] = cnt++;
    dfs(m, n, grafo, grid);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{

    fastIO;
    solve();
}