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
const int  mod=1e9+7;     const int maxn=2e5+50;
const int  inf=1e18+7;
typedef vector<int> vi;   typedef vector<vi> vvi;
typedef pair<int,int> pi; typedef vector<pi> vpi;
void ingraph(vi graph[], int m){int x, y;fr(i,0,m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}

int n,x;
int dp[1<<20];
int weight[1<<20];
int arr[20];

int weight_of_Submask(int mask){
	int wt=0;
	fr(i,0,20){
		if(mask&(1<<i))
			wt+=arr[i];
	}
	return wt;
}

int rec(int mask){ // mask i will store which all digits that I have taken

	if(mask==0)
		return 0;
	if(dp[mask]!=-1)
		return dp[mask];
	int ans=n;
	for(int subMask=mask;subMask;subMask=(subMask-1)&mask){
		if(x>=weight_of_Submask(subMask)){
			ans=min(ans,1+rec(mask^subMask));
		}	
	}

	return dp[mask]=ans;


}


void solve(){
     cin>>n>>x;
     fr(i,0,n)
     	cin>>arr[i];
     mem(dp,-1);
     int ans=rec((1<<n)-1);
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
  
  cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}
