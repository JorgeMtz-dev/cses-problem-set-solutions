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
void dfs(string curr,map<string,vector<char>>&grafo,string &ans){
    while(!grafo[curr].empty()){
        char x = grafo[curr].back();
        grafo[curr].pop_back();
        dfs(curr.substr(1)+x,grafo,ans);
        ans += x;
    }    
}

void solve() {
    
    int n;
    cin>>n;

    if(n == 1){
        cout<<"10"<<endl;
        return;
    }

    string str = "01";
    map<string,vector<char>>grafo;
    string inicio(n-1,'0');
    
    for(int i=0;i < 1<<(n-1);i++){
        string node = "";
        int x = i;
        //genera los numeros en binario
        for(int j = 0;j < n-1;j++){
            node = str[x%2] + node;
            x/=2;
        }
        grafo[node].push_back('0');
        grafo[node].push_back('1');
    }
    //0001011100
    string ans = "";
    dfs(inicio,grafo,ans);
    cout<<ans+inicio<<endl;
}

int main() {

    fastIO;
    solve();
}