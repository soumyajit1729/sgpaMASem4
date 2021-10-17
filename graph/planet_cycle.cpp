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

int tel[maxn];
int ans[maxn];
int vis[maxn];
int cycleSZ[maxn],depth[maxn];
int isCycleNode[maxn];
int n;



void dfs(int curNode){
    vis[curNode]=1;

    int nextNode=tel[curNode];

    if(cycleSZ[nextNode]!=0){ // visited and answer of next node is known
        depth[curNode]=1+depth[nextNode];
        cycleSZ[curNode]= cycleSZ[nextNode];
        return;
    }
    else if(vis[nextNode]){ //visited  but answer for next node is unknown
        // calculating this cycle for the first time
        //means this is the root of the cycle
        
        // calculating the cycle
        vector<int>cycle;

        int u=nextNode;
        // cout<<"Cycle detection:"<<u<<"\n";
        while(((int)cycle.size())==0 || u^cycle[0]){
            cycle.push_back(u);
            u=tel[u];
        }

        // updating th depth of cylce node=0, and size of the cycel
        for(int i=0;i<(int)cycle.size();i++){
            cycleSZ[cycle[i]]=sz(cycle);
            
            isCycleNode[cycle[i]]=1;
        }
        cycle.clear();
        return;

    }else{
        dfs(nextNode);
        if(isCycleNode[curNode])
            depth[curNode]=0;
        else
            depth[curNode]=1+depth[nextNode];
        cycleSZ[curNode]= cycleSZ[nextNode];

    }


}

void solve(){
     cin>>n;
     fr(i,0,n){
        int x;
        cin>>x;x--;
        tel[i]=x;
     }

     for(int i=0;i<n;i++){
       if(vis[i]!=0)
      ww      continue;
        dfs(i);
     }

     for(int i=0;i<n;i++){
        cout<<depth[i]+cycleSZ[i]<<" ";
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
