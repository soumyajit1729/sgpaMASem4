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

void solve(){
     int n,q;
     cin>>n>>q;
     int a[n];
     fr(i,0,n)
     	cin>>a[i];
     int dp[n][30];
     for(int i=0;i<n;i++)
     	dp[i][0]=a[i]-1;
     for(int i=1;i<30;i++){
     	for(int j=0;j<n;j++){
     		dp[j][i]=dp[dp[j][i-1]][i-1];
     	}
     }
     while(q--){
     	int u,k;
     	cin>>u>>k;
     	u--;
     	for(int i=30;i>=0;i--){
     		if((1<<i)&k){
     			u=dp[u][i];

     		}
     	}
     	cout<<u+1<<"\n";
     }
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
