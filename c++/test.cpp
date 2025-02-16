#include <bits/stdc++.h>

using namespace std;

int dp[6001];

struct node
{
    int a,b;
};

int main()
{
    int n, m;
    cin >> m >> n;
    vector<node> ve(110);
    for (int i = 1; i <= n; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        ve[c].a = a;
        ve[c].b = b;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= ve[j].b)
            {
                dp[i] = max(dp[i], dp[i-ve[j].b]+ve[j].a);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}