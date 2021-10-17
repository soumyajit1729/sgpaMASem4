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
int arr[maxn];
int dp[maxn][105];

void solve(){
   cin>>n>>m;
   fr(i,0,n)
   	cin>>arr[i];
   	// mem(dp,-1);
   
   if(arr[0]){
   	dp[0][arr[0]]=1;
   }else{
   	fr(j,1,m+1)
	   	dp[0][j]=1;
   }

   for(int i=1;i<n;i++){
   	if(arr[i]!=0)
   		dp[i][arr[i]]=(dp[i-1][arr[i]-1]+dp[i-1][arr[i]]+dp[i-1][arr[i]+1])%mod;
   	else{
   		fr(j,1,m+1){
   			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
   		}
   	}
   }

   int ans=0;
   fr(j,1,m+1)
   ans=(ans+dp[n-1][j])%mod;
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
