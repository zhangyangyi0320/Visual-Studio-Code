#include <bits/stdc++.h>

using namespace std;

long long dp[110][110];
long long a[110];

int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        a[i] = a[i - 1] + ve[i];
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            dp[i][j] = 9223372036854775807;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]);
            }
        }
    }

    cout << dp[1][n];
    return 0;
}