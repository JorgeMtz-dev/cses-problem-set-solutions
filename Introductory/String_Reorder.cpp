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

void solve() {
    
    string str;cin>>str;
    vector<int>freq(26,0);
    for(auto x : str)freq[x-'A']++;

    string ans;

    while(SZ(ans) < SZ(str)){
        bool valio = true;
        for(int i = 0;i < 26;i++){
            if(freq[i] > 0 && (ans.empty() || ans.back() != (i+'A'))){
                
                freq[i]--;
                ans+=(i+'A');
                
                bool can = true;
                int remaining = SZ(str)-SZ(ans);
                for(int j = 0;j < 26;j++){

                    if(j != i){

                        if(freq[j] > (remaining+1)/2){
                            can = false;
                            break;
                        }
                        //ABABABA_ _ _ _ _
                        
                    }else{

                        if(freq[j] > remaining/2){
                            can = false;
                            break;
                        }

                    }

                }

                if(!can){
                    freq[i]++;
                    ans.pop_back();
                }else{
                    valio = false;
                    break;
                }

            }

        }
        if(valio)break;
    }

    if(ans.empty())cout<<-1<<endl;
    else cout<<ans<<endl;

}

signed main() {

    fastIO;
    solve();
}