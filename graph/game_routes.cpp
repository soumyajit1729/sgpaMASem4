#include<bits/stdc++.h>
using namespace std; 
 
#define fast              ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb                push_back
#define int               long long
#define lb                lower_bound
#define ub                upper_bound
#define ar                array
#define endl              '\n'
#define all(v)            (v).begin(), (v).end()
#define fr(i,a,b)         for( int i=a;i<b;i++)
#define mem(a,x)          memset(a,x,sizeof(a))
#define sz(x)             (int)(x).size()
#define op(x)             cout<<x<<endl
const int  mod=1e9+7;     const int maxn=1e5+50;
const int  inf=1e18+7;
typedef vector<int> vi;   typedef vector<vi> vvi;
typedef pair<int,int> pi; typedef vector<pi> vpi;
void ingraph(vi graph[], int m){int x, y;fr(i,0,m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}

vi adj[maxn];
int dp[maxn];
int n,m;

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int u,v;
    	cin>>u>>v;
    	u--;v--;
    	adj[u].push_back(v);
    }
    dp[0]=1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
    	int curNode=q.front();
    	q.pop();
    	for(auto v:adj[curNode]){
    		dp[v]=(dp[v]+dp[curNode])%mod;
    		q.push(v);
    	}
    }
    cout<<dp[n-1]<<"\n";
}

int32_t main()
{
  fast;

  int _t=1;
  // cin>>_t;
  while(_t--)
  {
    solve();
  }
  
  //cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}
