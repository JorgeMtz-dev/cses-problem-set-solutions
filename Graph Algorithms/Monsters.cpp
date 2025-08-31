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
int n,m;

int pos1D(int i,int j){
    return i*m+j;
}
pair<int,int>pos2D(int x){
    return {x/m,x%m};
}

bool isValid(int i,int j){
    return i>=0&&j>=0&&i<n&&j<m;
}

void bfsMonsters(vector<vector<char>>&grid,vector<vector<int>>&distMonsters){

    queue<int>q;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
           if(grid[i][j] == 'M'){
                q.push(pos1D(i,j));
                distMonsters[i][j] = 0;
           }
        }
    }

    while(!q.empty()){

        auto [x,y] = pos2D(q.front());
        q.pop();

        for(int i = 0;i < 4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isValid(nx,ny) && grid[nx][ny] != '#' && grid[nx][ny] != 'M'){

                if(distMonsters[nx][ny] > distMonsters[x][y] + 1){
                    distMonsters[nx][ny] = distMonsters[x][y] + 1;
                    q.push(pos1D(nx,ny));
                }

            }

        }

    }

}

void bfsEscape(int xx,int yy,vector<vector<char>>&grid,vector<vector<int>>&distHero,vector<vector<int>>&distMonsters,vector<vector<int>>&padres){

    queue<int>q;
    q.push(pos1D(xx,yy));
    distHero[xx][yy] = 0;
    string str = "DRUL";

    while(!q.empty()){

        auto [x,y] = pos2D(q.front());
        q.pop();

        for(int i = 0;i < 4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isValid(nx,ny) && grid[nx][ny] != '#'){

                if(distHero[nx][ny] > distHero[x][y] + 1){
                    distHero[nx][ny] = distHero[x][y] + 1;
                    if(distHero[nx][ny] < distMonsters[nx][ny] && padres[nx][ny] == -2){
                        q.push(pos1D(nx,ny));
                        grid[nx][ny] = str[i];
                        padres[nx][ny] = pos1D(x,y);
                    }
                }

            }

        }

    }

}


void recoverPath(int i ,int j,string &path,vector<vector<int>>&padres,vector<vector<char>>&grid){
    while(padres[i][j] != -1){
        path += grid[i][j];
        auto [x,y] = pos2D(padres[i][j]);
        i = x;j = y;
    }
    reverse(all(path));
}


void solve() {
    
    cin>>n>>m;
    pair<int,int>start;
    vector<vector<char>>grid(n,vector<char>(m,'#'));
    vector<vector<int>>distMonsters(n,vector<int>(m,INT_MAX));
    vector<vector<int>>distHero(n,vector<int>(m,INT_MAX));
    vector<vector<int>>padres(n,vector<int>(m,-2));
    string path;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'A'){
                start = {i,j};
            }
        }
    }

    bfsMonsters(grid,distMonsters);
    
    padres[start.first][start.second] = -1;
    bfsEscape(start.first,start.second,grid,distHero,distMonsters,padres);
    
    bool ok = false;
    for(int i = 0;i < n && !ok;i++){
        if(padres[i][0] != -2){
            recoverPath(i,0,path,padres,grid);
            ok = true;
        }
        if(ok)continue;
        if(padres[i][m-1] != -2){
            recoverPath(i,m-1,path,padres,grid);
            ok = true;
        }

    }
    for(int j = 0;j < m && !ok;j++){
        if(padres[0][j] != -2){
            recoverPath(0,j,path,padres,grid);
            ok = true;
        }
        if(ok)continue;
        if(padres[n-1][j] != -2){
            recoverPath(n-1,j,path,padres,grid);
            ok = true;
        }
    }

    if(!ok){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<SZ(path)<<endl;
    cout<<path<<endl;
    

}

int main() {

    fastIO;
    solve();
}