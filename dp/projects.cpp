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
     int n;
     cin>>n;
     vector< array<int,3> >proj(n);// {e,s,p}
     for(int i=0;i<n;i++){
     	cin>>proj[i][1]>>proj[i][0]>>proj[i][2];
     }
     sort(all(proj));
     set< array<int,2> >st;// {ending,maxProfit}
     st.insert({0,0}); // ending 0-->profit 0
     int maxProfitTillNow=0;

     for(int i=0;i<n;i++){

     	int r=proj[i][0];
     	int l=proj[i][1];
     	// cout<<"-----------------------------\n";
     	
     	auto it=st.lower_bound({l});
     	it--;
     	// cout<<l<<" "<<r<<" "<<(*it)[1]<<"\n";
     	int exclProfit=maxProfitTillNow;
     	int inclProfit=proj[i][2]+ (*it)[1];
     	maxProfitTillNow=max(inclProfit,exclProfit);

     	it=st.lower_bound({r});
     	if(it!=st.end())
     		st.erase(it);
     	st.insert({r,maxProfitTillNow});
     	
     }
     // for(auto it:st){
     // 	cout<< it[0]<<" "<<it[1]<<"\n";
     // }
     cout<<maxProfitTillNow<<"\n";
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
