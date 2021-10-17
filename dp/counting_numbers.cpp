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

string a,b;
int len;
int dp[20][2][2][12][2];
void makeEqualLength(){
	string tmp="";
	int len1=sz(a);
	int len2=sz(b);
	int diff=len2-len1;
	while(diff--)
		tmp+='0';

	a=tmp+a;
	// cout<<a<<"\n";
	// cout<<b<<"\n";
}

int rec(int level,int ut,int lt,int lastD,int flag){
	
	if(level==len){
		return 1;
	}

	if(dp[level][ut][lt][lastD][flag]!=-1)
		return dp[level][ut][lt][lastD][flag];

	int loB=0,upB=9;
	if(lt){
		loB=a[level]-'0';		
	}
	if(ut){
		upB=b[level]-'0';
	}

	int ans=0;
	for(int i=loB;i<=upB;i++){
		if(i==lastD)
		{
			if(i!=0)
				continue;
			if(i==0&&!flag)
				continue;
		}
		int nut=ut,nlt=lt,nflag=flag;
		if(i!=a[level]-'0')
			nlt=0;
		if(i!=b[level]-'0')
			nut=0;
		if(i!=0)
			nflag=0;
		ans=(ans+rec(level+1,nut,nlt,i,nflag));
	}

	return dp[level][ut][lt][lastD][flag]=ans;
}


void solve(){
     cin>>a>>b;
     makeEqualLength();
     mem(dp,-1);
     len=sz(b);
     int ans=rec(0,1,1,10,1);
     
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
