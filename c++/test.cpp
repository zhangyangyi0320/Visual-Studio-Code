#include <bits/stdc++.h>

using namespace std;

int dp[210][210];
int a[210];

int main()
{
    int n;
    cin >> n;
    vector<int> ve(210);
    for (int i = 1; i <= n; i++)
    {
        cin >> ve[i];
        ve[i + n] = ve[i];
    }
    for (int i = 1; i <= (n << 1); i++)
    {
        a[i] = a[i - 1] + ve[i];
    }
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1, j = l; j <= (n << 1); i++, j++)
        {
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]);
            }
        }
    }
    int ans = INT_MAX;
    for(int i=1;i<=n;i++)
    {
        ans = min(ans,dp[i][i+n-1]);
    }
    cout << ans;
    return 0;
}