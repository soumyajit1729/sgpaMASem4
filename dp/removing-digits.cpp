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
const int maxn=1e6+50;     const int  inf=1e14+7;
typedef vector<int> vi;   typedef vector<vi> vvi;
typedef pair<int,int> pi; typedef vector<pi> vpi;
void ingraph(vi graph[], int m){int x, y;fr(i,0,m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}

int dp[maxn];

int rec(int n){
	if(n==0) // base case
		return 0;
	// cout<<n<<"\n";
	// use caching
	if(dp[n]!=-1)
		return dp[n];

	int digits[10]={0};// digits[i]!=0-->i th digit exist
	int n1=n;
	// extracting the digits
	while(n1){
		digits[n1%10]++;
		n1/=10;
	}
	if(n1>0)
		digits[n1]++;


	int ans=inf;
	for(int i=1;i<=9;i++){
		if(digits[i]!=0){ // i th digits exist in n
			ans=min(ans,1+rec(n-i));
		}
	}

	return dp[n]=ans;
}

void solve(){
 	int n;
 	cin>>n;
 	mem(dp,-1);
 	int ans=rec(n);
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
