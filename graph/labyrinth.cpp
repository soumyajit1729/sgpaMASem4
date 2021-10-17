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
const int  mod=1e9+7;     const int maxn=1e3+50;
const int  inf=1e9+7;
typedef vector<int> vi;   typedef vector<vi> vvi;
typedef pair<int,int> pi; typedef vector<pi> vpi;
void ingraph(vi graph[], int m){int x, y;fr(i,0,m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}
 
int numRooms=1;
int n,m;
string s[maxn];
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
int dp[maxn][maxn];
 
 
void solve(){
    cin>>n>>m;
 
    fr(i,0,n)
    	cin>>s[i];
    int sx=-1,sy=-1,ex=-1,ey=-1;
    fr(i,0,n){
    	fr(j,0,m){
    		dp[i][j]=inf;
    		if(s[i][j]=='A'){
    			sx=i;sy=j;
    		}else if(s[i][j]=='B'){
    			ex=i;ey=j;
    		}
    	}
 
    }
 
    queue< ar<int,2>>q;
    q.push({sx,sy});
    dp[sx][sy]=0;
    bool flag=true;
    while(!q.empty()&&flag){
    	int cx=(q.front())[0];
    	int cy=(q.front())[1];
    	if(cx==ex&&cy==ey)
    		break;
    	q.pop();
    	for(int i=0;i<4;i++){
    		int nx=cx-x[i];
    		int ny=cy-y[i];
    		if(nx<0||ny<0||nx>=n||ny>=m||s[nx][ny]=='#')
    			continue;
    		if(dp[nx][ny]>dp[cx][cy]+1){
    			dp[nx][ny]=dp[cx][cy]+1;
    			if(nx==ex&&ny==ey)
    				flag=false;
    			q.push({nx,ny});
    		}
    	}
    } 
    map< pair<int,int>,char >mp;
    mp[{0,1}]='R';
    mp[{0,-1}]='L';
    mp[{1,0}]='D';
    mp[{-1,0}]='U';
 
    if(dp[ex][ey]==inf){
    	cout<<"NO\n";
    }else{
    	cout<<"YES\n";
    	cout<<dp[ex][ey]<<"\n";
    	string ans="";
    	int cx=ex,cy=ey;
    	int dist=dp[ex][ey];
    	while(dist--){
    		// cout<<dist<<"\n";
    		for(int i=0;i<4;i++){
    			int nx=cx-x[i];
    			int ny=cy-y[i];
    			if(nx>=0&&ny>=0&&nx<n&&ny<m){
    				if(dp[nx][ny]==dist-1){
    					cx=nx;cy=ny;
    					ans+=mp[{x[i],y[i]}];
    					goto answer;
    				}
    			}
    		}
    		answer:
    			int x;
    		
    	}
    	reverse(all(ans));
    	int d=0;
    	fr(i,0,sz(ans)){
    		if(ans[i]=='D')
    			d++;
    	}
    	cout<<d<<"\n";
    	d=0;
    	fr(i,0,sz(ans))
    	if(ans[i]=='U')
    		d++;
    	cout<<d<<"\n";
    	cout<<sz(ans)<<"\n";
    	cout<<ans<<"\n";
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