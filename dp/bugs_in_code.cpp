#include<bits/stdc++.h>
#define p 1000000007
using lli = long long int;
using namespace std;

int n,m,b;
int arr[505];

int dp[505][505][505];
int rec(int man, int line, int bugs){
    if (line<0 || bugs<0)
    {
        return 0;
    }
    if(man==-1){
        if(line==0) return 1;
        return 0;
    }

    if(dp[man][line][bugs]!=-1){
        return dp[man][line][bugs];
    }

    lli ans = rec(man-1, line, bugs) + rec(man, line-1, bugs-arr[man]);
    ans%=p;

    return (dp[man][line][bugs] = ans);
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>b;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1, m, b)<<"\n";
}
