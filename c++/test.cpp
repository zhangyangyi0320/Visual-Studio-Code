#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    cin >> m;
    vector<vector<int>> w(m, vector<int>(3));
    for (int i = 0; i < m; ++i) {
        cin >> w[i][0] >> w[i][1] >> w[i][2];
    }
    int k;
    cin >> k;
    vector<int> dp(k + 1, 0);
    for (const auto& w : w) {
        int p = w[1];
        int d = w[2];
        for (int j = p; j <= k; ++j) {
            dp[j] = max(dp[j], dp[j - p] + d);
        }
    }
    cout << dp[k] << endl;
    return 0;
}
