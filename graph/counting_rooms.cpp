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
const int  mod=1e9+7;     const int maxn=1e3+50;
const int  inf=1e18+7;
typedef vector<int> vi;   typedef vector<vi> vvi;
typedef pair<int,int> pi; typedef vector<pi> vpi;
void ingraph(vi graph[], int m){int x, y;fr(i,0,m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}

int numRooms=1;
int n,m;
string s[maxn];
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
int dp[maxn][maxn];

void rec(int cx,int cy){
	dp[cx][cy]=numRooms;
	for(int i=0;i<4;i++){
		int nx=cx-x[i];
		int ny=cy-y[i];
		if(nx<0||ny<0||nx>=n||ny>=m||dp[nx][ny]!=0)
			continue;
		rec(nx,ny);
	}
}


void solve(){
    cin>>n>>m;

    fr(i,0,n)
    	cin>>s[i];
    fr(i,0,n){
    	fr(j,0,m){
    		if(s[i][j]=='#')
    			dp[i][j]=-1;
    	}
    }

    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(dp[i][j]==0){
    			rec(i,j);
    			numRooms++;
    		}
    	}
    }
    cout<<numRooms-1<<"\n";

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
