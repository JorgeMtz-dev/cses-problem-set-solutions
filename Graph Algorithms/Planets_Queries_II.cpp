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
const int blanco = 0,gris = 1,negro = 2,pCiclo = 3;

void show(vector<int>&arr){
  for(auto x : arr){
      cout<< x <<' ';
  }
  cout << endl;
}

struct DSU {
    vector<int> e;
    void init(int n) { e = vector<int>(n, -1); }
    int size(int x) { return -e[get(x)]; }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool join(int a, int b) {
        a = get(a), b = get(b);
        if (a == b)
            return false;
        if (e[a] > e[b])
            swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

void dfs(int node,vector<int>&A,vector<int>&visited,int &ini){

    int next = A[node];
    if(visited[next]==blanco){
        visited[next]=gris;
        dfs(next,A,visited,ini);
        visited[next]=negro;
    }else if(visited[next] == gris){
        ini = next;
    }

}
queue<pair<int,int>>q;
void ciclo(int node,vector<int>&A,vector<int>&visited){
    q.push({node,0});
    visited[node]=pCiclo;
    int next = A[node];
    while(next != node){
        visited[next]=pCiclo;
        q.push({next,0});
        next = A[next];
    }
}

int bfs(vector<vector<int>>&noA,vector<int>&dists,vector<int>&visited,int &cntciclos){
    int cnt = 1;
    while(!q.empty()){

        auto [node,dist] = q.front();
        if(dist == 0){
            visited[node]=cntciclos;
            dists[node] = cnt++;
        }else{
            dists[node] = dist;
        }
        q.pop();
        for(auto next : noA[node]){
            if(visited[next] < pCiclo)
                q.push({next,dist+1});
        }

    }
    return cnt-1;

}

void solve() {
    
    int n,q;cin>>n>>q;
    int LOG = ceil(log2(1e9));
    vector<int>A(n);
    vector<vector<int>>noA(n,vector<int>());
    vector<vector<int>>succ(n,vector<int>(LOG));
    vector<int>dists(n,0);
    vector<int>visited(n,blanco);
    vector<int>maxCiclo;
    int cntciclos = 3;
    DSU dsu;dsu.init(n);

    for(int i = 0;i < n;i++){
        int x;cin>>x;
        //indexado 0
        x--;
        //grafo al revez
        noA[x].push_back(i);
        //unir componentes
        dsu.join(i,x);
        //i conecta con x
        A[i]=x;
        //el primer nodo de i es x
        succ[i][0] = x;
    }
    for(int i = 0;i < n;i++){
        int ini = -1;
        //nunca visitado
        if(visited[i] == blanco){
            //busca ciclos
            visited[i]=gris;
            dfs(i,A,visited,ini);
            visited[i]=negro;
        }
        //si hay ciclo
        if(ini != -1){
            //obtener los nodos del ciclo
            ciclo(ini,A,visited);
            //calcular las distancias del ciclo a los
            //demas nodos
            maxCiclo.push_back(bfs(noA,dists,visited,cntciclos));
            cntciclos++;
            
        }
    }
    /*for(auto x : maxCiclo)cout<<x<<" ";
    cout<<endl;
    cout<<cntciclos<<endl;*/
    for(int k = 1;k < LOG;k++){
        for(int i = 0;i < n;i++){
            //calcular los sucesores
            succ[i][k] = succ[succ[i][k-1]][k-1];
        }
    }
/*    for(auto x : dists){
        cout<<x<<' ';
    }
    cout<<endl;
    for(auto x : visited){
        cout<<x<<' ';
    }
    cout<<endl;
*/
    while(q--){

        int x,y;cin>>x>>y;
        x--;y--;
        //componente diferente
        if(dsu.get(x) != dsu.get(y)){
            cout<<-1<<endl;
            continue;
        }
        //x en ciclo , y fuera de ciclo , por lo tanto 
        //no se puede visitar
        if(visited[x] >= pCiclo && visited[y] < pCiclo){
            cout<<-1<<endl;
            continue;
        }
        //ambos fuera de ciclo
        if(visited[x] < pCiclo && visited[y] < pCiclo){
            //x esta mas cerca que y
            //por lo  tanto no se puede alcanzar
            if(dists[x] < dists[y]){
                cout<<-1<<endl;
            }else{
                
                int k = dists[x] - dists[y];
                for(int i = LOG-1;i >= 0;i--){
                    if(k & (1<<i)){
                        x = succ[x][i];
                    }
                }
                //no se llego a y
                if(x != y){
                    cout<<-1<<endl;
                }else{
                    //ya chingamos
                    cout<<k<<endl;
                }
            }
            continue;
        }
        //ambos dentro del mismo ciclo
        if(visited[x] >= pCiclo && visited[y] >= pCiclo){
            //ya chingamos
            //cout<<x<<' '<<y<<endl;

            int maxi = maxCiclo[visited[x]-pCiclo];
            if(dists[x] > dists[y])
                cout<<maxi-max(dists[x],dists[y]) + min(dists[x],dists[y]) <<endl;
            else
                cout<<dists[y]-dists[x]<<endl;

            continue;
        }
        //x fuera de ciclo ,y dentro de ciclo
        if(visited[x] < pCiclo && visited[y] >= pCiclo){
            //ya chingamos
            //distancia de x al ciclo
            int k = dists[x];
            //nos vamos al primer sucesor de x
            //que es parte del ciclo
            for(int i = LOG-1;i >= 0;i--){
                if(k & (1<<i)){
                    x = succ[x][i];
                }
            }
            int maxi = maxCiclo[visited[y]-pCiclo];
            if(dists[x] > dists[y])
                cout<<maxi-max(dists[x],dists[y])+min(dists[x],dists[y])+k<<endl;
            else
                cout<<dists[y]-dists[x]+k<<endl;
            
            continue;
        }
        

    }

}

int main() {

    fastIO;
    solve();
}