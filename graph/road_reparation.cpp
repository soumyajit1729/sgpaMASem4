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

int n,m;
int numCoins[maxn],indegree[maxn],dp[maxn],vis[maxn];
vi adj[maxn];
vi topo;


void dfs(int u){
  vis[u]=1;
  for(auto v:adj[u]){
    if(vis[v])
      continue;
    dfs(v);
  }
  topo.push_back(u);
}

// void topoSort(){
//   queue<int>q;
//   for(int i=0;i<n;i++){
//     if(indegree[i]==0)
//       q.push(i);
//   }

//   while(!q.empty()){
//     int u=q.front();
//     cout<<u<<"\n";
//     q.pop();
//     topo.pb(u);
//     for(auto v:adj[u]){
//       indegree[v]--;
//       if(indegree[v]==0){
//         q.push(v);
//       }
//     }
//   }


// }


void solve(){
    cin>>n>>m;
    fr(i,0,n)
      cin>>numCoins[i];

    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;u--;v--;
      if(u==v)
        continue;
      adj[u].push_back(v);
      // indegree[v]++;
    }

    for(int i=0;i<n;i++)
      if(vis[i]==0)
        dfs(i);

    reverse(all(topo));
    set<int>s;
    for(int i=n-1;i>=0;i--){
      int u=topo[i];
      dp[u]=max(dp[u],numCoins[u]);
      s.insert(u);
      for(auto v:adj[u]){
        if(s.find(v)!=s.end())
        {
          dp[u]=max(dp[u],numCoins[u]+dp[v]);
        }
      }
    }

    int ans=0;
    for(int i=0;i<n;i++)
      ans=max(ans,dp[i]);
    cout<<ans<<"\n";


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
