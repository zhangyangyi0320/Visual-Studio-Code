#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
vector<int> ve[MAXN];
int dp[MAXN][2], root[MAXN], n, cnt;
bool flag;
void dfs(int x, int fa)
{
    if (flag)
    {
        return;
    }
    root[x] = 1;
    for (int i = 0; i < ve[x].size(); i++)
    {
        int y = ve[x][i];
        if (y == fa)
        {
            continue;
        }
        dfs(y, x);
        root[x] += root[y];
    }
    if (root[x] > 3)
    {
        flag = 1;
    }else if (root[x] == 3)
    {
        if(fa)
        {
            root[x] = 0;
            cnt++;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    flag = 0;
    if (n % 3)
    {
        cout << -1;
    }
    else
    {
        dfs(1, 0);
        if (flag)
        {
            cout << -1;
        }
        else
        {
            cout << cnt;
        }
    }
    return 0;
}