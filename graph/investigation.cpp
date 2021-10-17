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
const int  inf=1e16+7;
typedef vector<int> vi;   typedef vector<vi> vvi;
typedef pair<int,int> pi; typedef vector<pi> vpi;
void ingraph(vi graph[], int m){int x, y;fr(i,0,m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}

int n,m;
vector< ar<int,2> > adj[maxn]; // {edge_cost,next_city}
vi adj2[maxn];

int vis[maxn];
int minFlight[maxn],maxFlight[maxn],numWays[maxn],minDist[maxn];

void dfs(int u){
	vis[u]=1;
	for(auto v:adj2[u]){
		if(vis[v]==0) // avoiding repetitive calls
			dfs(v);
		numWays[u]=(numWays[u]+numWays[v])%mod;
		minFlight[u]=min(minFlight[u],minFlight[v]+1); // here don't required as if there is not any path it's value is infinity
		if(maxFlight[v]!=-1) // there is path exist from  v to n-1 then only we will update
		maxFlight[u]=max(maxFlight[u],maxFlight[v]+1);
	}
}


void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,cost;
		cin>>a>>b>>cost;
		a--;b--;
		adj[a].push_back({cost,b});
	}
	// 1st task calculating minimum distance
	// doing dijkstra algo from node 1
	for(int i=0;i<maxn;i++) 
		minDist[i]=inf;
	priority_queue< ar<int,2>, vector< ar<int,2> >, greater< ar<int,2> > > pq; // minheap {cost,node}
	pq.push({0,0});
	minDist[0]=0;
	while(!pq.empty()){
		ar<int,2> p=pq.top();
		pq.pop();
		int curNode=p[1];
		int cost=p[0];
		if(minDist[curNode]<cost) // already discovered
			continue;
		for(auto node:adj[curNode]){
			int childNode=node[1];
			int edgeCost=node[0];

			if(minDist[childNode]>minDist[curNode]+edgeCost){
				minDist[childNode]=minDist[curNode]+edgeCost;
				pq.push({minDist[childNode],childNode});
			}
		}
	}


	cout<<minDist[n-1]<<" ";


	// part 2
	// creating a DAG from the dijkstra path
	for(int i=0;i<n;i++){
		for(auto v:adj[i]){
			if(minDist[v[1]]==minDist[i]+v[0]){ // v[0] is edge cost from i-->v[1]
				adj2[i].push_back(v[1]);
			}
		}
	}


	// calculate part2,3,4
	for(int i=0;i<n;i++)
		minFlight[i]=inf;
	minFlight[n-1]=0;
	memset(maxFlight,-1,sizeof(maxFlight));
	maxFlight[n-1]=0;
	numWays[n-1]=1;
	dfs(0);
	cout<<numWays[0]<<" "<<minFlight[0]<<" "<<maxFlight[0]<<"\n";



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
