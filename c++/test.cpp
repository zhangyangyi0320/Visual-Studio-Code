#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+10;
vector<int> ve[MAXN];
int dp[MAXN][2];

void dfs(int u, int a) {
    dp[u][0] = 0;
    dp[u][1] = INT_MAX;
    int cnt = 0;

    for (int v : ve[u]) {
        if (v == a) continue;
        dfs(v, u);
        cnt++;

        dp[u][0] += min(dp[v][0], dp[v][1]);

        if (dp[v][1] != INT_MAX) {
            dp[u][1] = min(dp[u][1], dp[v][1] + dp[u][0] - min(dp[v][0], dp[v][1]));
        }
    }

    if (cnt < 2) {
        dp[u][1] = INT_MAX;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }

    dfs(1, -1);

    if (dp[1][1] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[1][1] << endl;
    }

    return 0;
}
