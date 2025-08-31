#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<pair<int, int>>> parent;
vector<vector<bool>> visited;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char dir[] = {'D', 'R', 'U', 'L'};

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] != '#')
            {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y}; // Guarda el padre para reconstruir camino
                q.push({nx, ny});
            }
        }
    }
}

string reconstructPath(pair<int, int> start, pair<int, int> end)
{
    string path;
    pair<int, int> cur = end;

    while (cur != start)
    {
        auto [px, py] = parent[cur.first][cur.second];

        for (int k = 0; k < 4; ++k)
        {
            if (px + dx[k] == cur.first && py + dy[k] == cur.second)
            {
                path += dir[k];
                break;
            }
        }

        cur = {px, py};
    }

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    pair<int, int> start, end;
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'B')
                end = {i, j};
        }
    }

    bfs(start);

    if (!visited[end.first][end.second])
    {
        cout << "NO\n";
    }
    else
    {
        string path = reconstructPath(start, end);
        cout << "YES\n";
        cout << path.length() << "\n";
        cout << path << "\n";
    }

    return 0;
}
