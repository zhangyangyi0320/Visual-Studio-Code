#include <bits/stdc++.h>

using namespace std;

long long dp[1010];

struct node
{
    int b,a;
};

int main()
{
    int n, m;
    cin >> m >> n;
    vector<node> ve[110];
    for (int i = 1; i <= n; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        ve[c].push_back({a,b});
    }
    for (int i = 1; i <= 100; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 0; k < ve[i].size(); k++)
            {
                if (j >= ve[i][k].b)
                {
                    dp[j] = max(dp[j], dp[j-ve[i][k].b]+ve[i][k].a);
                }
            }
        }
    }
    cout << dp[m];
    return 0;
}