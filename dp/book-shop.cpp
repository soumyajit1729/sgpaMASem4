#include<bits/stdc++.h>
using namespace std; 
 
#define fast              ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb                push_back
// #define int               long long
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
const int maxn=1e5+50;  
const int  inf=1e8+7;
typedef vector<int> vi;   typedef vector<vi> vvi;
typedef pair<int,int> pi; typedef vector<pi> vpi;
void ingraph(vi graph[], int m){int x, y;fr(i,0,m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}
 
int n,x;
int prices[1005];
int pages[1005];
int dp[1005][maxn];
 
int rec(int level,int remPrice){
	if(remPrice<0) // inValid state , pruning
		return -inf;
 
	if(level==-1){ // base case
		if(remPrice>=0)
			return 0;
		return -inf;
	}
 
	if(dp[level][remPrice]!=-1)
		return dp[level][remPrice];
	int excBook=-inf,incBook=-inf;
	excBook=rec(level-1,remPrice);
	if(remPrice-prices[level]>=0)
			incBook=pages[level]+rec(level-1,remPrice-prices[level]);
 
	return dp[level][remPrice]=max(incBook,excBook);
}
 
void solve(){
     cin>>n>>x;
     fr(i,0,n)
     	cin>>prices[i];
     fr(i,0,n)
     	cin>>pages[i];
     for(int i=1;i<=n;i++){
     	for(int j=1;j<=x;j++){
     		dp[i][j]=max(dp[i-1][j],dp[i][j]);
     		if(j-prices[i-1]>=0)
     			dp[i][j]=max(dp[i][j],dp[i-1][j-prices[i-1]]+pages[i-1]);
     	}
     }
     cout<<dp[n][x]<<"\n";
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
  
  cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}