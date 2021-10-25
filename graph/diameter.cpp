#include <bits/stdc++.h>
#define p 1000000007
#define PB push_back

using lli = long long int;
using namespace std;

lli n;
vector<lli> g[200010];
lli dist[200010];

void bfs(lli sc){
	for (int i = 1; i <= n; ++i)
    {
    	dist[i]=1e18;
    }
	dist[sc]=0;
	queue<lli> pq;
	pq.push(sc);

	while(!pq.empty()){
		lli cur = pq.front();
		pq.pop();

		for(auto v:g[cur]){
			if (dist[v]>dist[cur]+1)
			{
				dist[v] = dist[cur]+1;
				pq.push(v);
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
    	lli a,b;
    	cin>>a>>b;
    	g[a].PB(b);
    	g[b].PB(a);
    }

    bfs(1);
    lli maxdist = -1;
    lli maxdistnode = -1;
    for (int i = 1; i <= n; ++i)
    {
    	if (maxdist<dist[i])
    	{
    		maxdist = dist[i];
    		maxdistnode = i;
    	}
    }
    
    bfs(maxdistnode);
    maxdist = -1;
    for (int i = 1; i < n+1; ++i)
    {
    	maxdist = max(maxdist, dist[i]);
    }
    cout<<maxdist<<"\n";

}