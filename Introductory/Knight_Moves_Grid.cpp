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
int N;
int pos(int i, int j)
{
    return i * N + j;
}

bool isValid(int i, int j)
{
    return i >= 0 && i < N && j >= 0 && j < N;
}

void bfs(vector<vector<int>> &grafo, vector<vector<int>> &grid)
{

    queue<pair<int, int>> q;
    q.push({pos(0, 0), 0});
    grid[0][0] = 0;
    while (!q.empty())
    {

        auto [pos, cnt] = q.front();
        q.pop();

        for (auto x : grafo[pos])
        {

            if (grid[x / N][x % N] == -1)
            {
                grid[x / N][x % N] = cnt + 1;
                q.push({x, cnt + 1});
            }
        }
    }
}

void solve()
{
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N, -1));
    vector<vector<int>> grafo(N * N, vector<int>());
    vector<int> di = {-2, -2, 2, 2, 1, -1, 1, -1};
    vector<int> dj = {1, -1, 1, -1, -2, -2, 2, 2};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (isValid(i + di[k], j + dj[k]))
                {
                    grafo[pos(i, j)].push_back(pos(i + di[k], j + dj[k]));
                }
            }
        }
    }
    int cnt = 1;
    grid[0][0] = 0;
    bfs(grafo, grid);

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