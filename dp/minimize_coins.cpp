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
const int  mod=1e9+7;    
const int maxn=1e6+50;     const int  inf=1e18+7;
typedef vector<int> vi;   typedef vector<vi> vvi;
typedef pair<int,int> pi; typedef vector<pi> vpi;
void ingraph(vi graph[], int m){int x, y;fr(i,0,m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}

int cost[maxn];
int dp[maxn];
int n,x;

int rec(int remN){
	if(remN<0) // pruning
		return inf;
	if(remN==0){// base case
		return 0;
	}
	if(dp[remN]!=-1)
		return dp[remN];

	int ans=inf;

	for(int i=0;i<n;i++){
		ans=min(ans,1+rec(remN-cost[i]));
	}

	return dp[remN]=ans;

}



void solve(){
    
    cin>>n>>x;
    fr(i,0,n)
    	cin>>cost[i];
    mem(dp,-1);

    int ans=rec(x);
    if(ans>=inf)
    	ans=-1;
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
