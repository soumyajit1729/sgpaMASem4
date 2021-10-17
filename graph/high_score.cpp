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
const int  mod=1e9+7;     const int maxn=2550;
const int  inf=1e18+7;
typedef vector<int> vi;   typedef vector<vi> vvi;
typedef pair<int,int> pi; typedef vector<pi> vpi;
void ingraph(vi graph[], int m){int x, y;fr(i,0,m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}

vector< ar<int,2> >adj[maxn]; // adj[u]-->{v,cost}
vi neigh[maxn];
int indegree[maxn];
int vis[maxn],vis2[maxn];
int n,m;
vi topo;

vi maxDist(maxn,-inf);
vi firIt(maxn);

bool flag=false;

void dfs(int u){
  // cout<<"u :"<<u<<"\n";
  vis2[u]=1;
  if(vis[u]==1&&maxDist[u]>firIt[u])
  {
    flag=true;
    return;
  }

  for(auto v:neigh[u]){
    if(vis2[v]==0){
      dfs(v);
    }
  }
}

int k1;

void topoSort(int u){
	vis[u]=k1;
	for(auto node:adj[u]){
		int v=node[0];
		if(vis[v]==0){
			topoSort(v);
		}
	}
	topo.pb(u);
}


void solve(){
     cin>>n>>m;
     for(int i=0;i<m;i++){
     	int u,v,cost;
     	cin>>u>>v>>cost;
     	u--;v--;
     	adj[u].pb({v,cost});
      neigh[v].pb(u);
     	indegree[v]++;
     }

     fr(i,0,n)
     	if(vis[i]==0)
      {
        k1++;
     		topoSort(i);
      }
     reverse(all(topo));
     // vi maxDist(n,-inf); // initializing the distance of nodes with -inf
     maxDist[0]=0; // starting point

     for(int i=0;i<sz(topo);i++){
     	int curNode=topo[i];
     	for(auto node:adj[curNode]){
     		int childNode=node[0];
     		int edgeCost=node[1];
     		maxDist[childNode]=max(maxDist[childNode],maxDist[curNode]+edgeCost);
     	}
     }
    
     fr(i,0,n)
     firIt[i]=maxDist[i];

     for(int i=0;i<sz(topo);i++){
     	int curNode=topo[i];
     	for(auto node:adj[curNode]){
     		int childNode=node[0];
     		int edgeCost=node[1];
     		maxDist[childNode]=max(maxDist[childNode],maxDist[curNode]+edgeCost);
     	}
     }
    // mem(vis,0);
     dfs(n-1);
     // cout<<"------------------------\n";
     // fr(i,0,n)
     // 	cout<<maxDist[topo[i]]<<" ";
     // cout<<"\n";

    
     if(flag) // there is +ve cycle
     	cout<<"-1\n";
     else cout<<maxDist[n-1]<<"\n";


    
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
