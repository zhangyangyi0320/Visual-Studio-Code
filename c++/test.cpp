#include <bits/stdc++.h>

using namespace std;

int dp[110][110];
int a[110];

int main() {
    int n;
    cin >> n;
    vector<int> ve(110);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        a[i] = a[i - 1] + ve[i];
    }

    for (int i = 2; i <= 110; i++) {
        for (int j = 1; j + i - 1 <= n; j++) {
            int k = j + i - 1;
            dp[j][k] = INT_MAX;
            for (int l = j; l < k; l++) {
                dp[j][k] = min(dp[j][k], dp[j][l] + dp[l + 1][k] + a[k] - a[j - 1]);
            }
        }
    }

    cout << dp[1][n];
    return 0;
}