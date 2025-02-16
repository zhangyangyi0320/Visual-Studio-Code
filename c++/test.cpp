#include <bits/stdc++.h>

using namespace std;

int dp[110][110];
int a[110];

int main()
{
    int n;
    cin >> n;
    vector<int> ve(110);
    for (int i = 1; i <= n; i++)
    {
        cin >> ve[i];
        a[i] = a[i - 1] + ve[i];
    }

    for (int l = 2; l <= n; l++)
    {
        for (int i = 1, j = l; j <= n; i++, j++)
        {
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]);
            }
        }
    }

    cout << dp[1][n];
    return 0;
}