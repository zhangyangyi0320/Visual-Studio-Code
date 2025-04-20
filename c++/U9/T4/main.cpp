/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<pair<int, int> > > e(n+1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    vector<int> dis(n+1, 1e9+10), vis(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dis[1] = 0;
    q.push({0, 1});
    int cnt=0, ans=0;
    while (!q.empty())
    {
        int w = q.top().first;
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        ans += w;
        vis[u] = 1;
        cnt++;
        if(cnt == n)
            break;
        for (auto it : e[u])
        {
            int v = it.first;
            int d = it.second;
            if (dis[v] > d)
            {
                dis[v] = d;
                q.push({d, v});
            }
        }
    }
    if (cnt != n)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "orz" << endl;
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=10, m=20;
    vector<int>a(10);
    vector<vector<int>>b(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}