#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
#define endl '\n'
const int  mod=1e9+7;
#define inf 1e18
#define int long long
#define fr(i,a,b) for( int i=a;i<b;i++)
typedef vector<int> vi;typedef vector<vi> vvi;
typedef pair<int,int> pi;typedef vector<pi> vpi;
#define sz(x) (int)(x).size()
#define all(v)  (v).begin(), (v).end()
#define ar array
#define pb push_back
#define bp __builtin_popcountll
void ingraph(vi graph[], int m){int x, y;fr(i,0,m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}

const int maxn=1e5+5;
int adj[maxn];
int vis[maxn];

void dfs(int u,int col){
	vis[u]=col;
	for(auto v:adj[u]){
		if(vis[v]==0){
			dfs(v,3-col);
		}
	}
}
void solve(){
    int n,m;
    cin>>n>>m;
    ingraph(adj,m);
    fr(i,0,n)
    	if(vis[i]==0)
    		dfs(i);
    fr(i,0,n)
    	cout<<vis[i]<<" ";
    	

}

int32_t main()
{
  fast;

  int t=1;
  // cin>>t;
  while(t--)
  {
    solve();
  }
  
  //cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}