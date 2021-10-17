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

const int maxn=1e5+50;
vi adj[maxn];
int vis[maxn];
int parent[maxn];
int ans=-1,stat=-1;
bool flag=false;
void dfs(int u,int par,int dep){
	if(flag)
		return;
	cout<<u+1<<" check "<<par+1<<"\n";
	vis[u]=1;
	parent[u]=par;
	for(auto v:adj[u]){
		if(vis[v]==0){
			dfs(v,u,dep+1);
		}else if(dep>1){
			flag=true;
			ans=u;
			stat=v;
			return;
		}
	}
}

void solve(){
    int n,m;
    cin>>n>>m;
    ingraph(adj,m);
    fr(i,0,n){
    	if(vis[i]==0){
    		
    		dfs(i,-1,0);
    	}
    	if(flag)
    		break;
    }

    if(flag){
    	// cout<<"YES\n";
    	cout<<ans<<" "<<stat<<"\n";
    	vi tmp;
    	
    	while(ans!=parent[stat])
    	{
    		tmp.pb(ans);
    		ans=parent[ans];
    	}
    	tmp.pb(tmp[0]);
    	cout<<sz(tmp)<<"\n";
    	fr(i,0,sz(tmp))
    		cout<<tmp[i]+1<<" ";
    }else{
    	cout<<"IMPOSSIBLE\n";
    }

    fr(i,0,n)
    	cout<<i+1<<" "<<parent[i]+1<<"\n";
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