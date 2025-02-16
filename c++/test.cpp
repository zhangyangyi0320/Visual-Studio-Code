#include <bits/stdc++.h>

using namespace std;

int dp[6001];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> ve(n);
    for (int i = 0; i < n; ++i)
    {
        int v, w, s;
        cin >> v >> w >> s;
        ve[i] = make_tuple(v, w, s);
    }

    for (int a = 0; a < ve.size(); a++)
    {
        int v, w, s;
        for (int k = 1; s > 0; k <<= 1)
        {
            int x = min(k, s);
            s -= x;
            for (int j = m; j >= x * v; --j)
            {
                dp[j] = max(dp[j], dp[j - x * v] + x * w);
            }
        }
    }

    cout << dp[m] << endl;
    return 0;
}