#include <bits/stdc++.h>

using namespace std;

int a[110],dp[110];
vector<int> adj[110];
int n;

void dfs(int u,int b)
{
    dp[u] = a[u];
    for(int j=0;j<adj[u].size();j++)
    {
        int v = adj[u][j];
        if(v!=b)
        {
            dfs(v,u);
            if(dp[v]>0)
                dp[u] += dp[v];
        }
    }
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    int ans = 0;
    for(int i=1;i<=n;i++)
        ans = max(ans,dp[i]);
    cout << ans;
    return 0;
}