#include <bits/stdc++.h>

using namespace std;

int main() {
    int C, n;
    cin >> C >> n;
    vector<int> w1(n);
    vector<int> v1(n);
    vector<int> c1(n);
    for (int i = 0; i < n; ++i) {
        cin >> w1[i] >> v1[i] >> c1[i];
    }
    vector<int> dp(C + 1, 0);
    for (int i = 0; i < n; ++i) {
        int w = w1[i];
        int v = v1[i];
        int c = c1[i];
        for (int k = 1; k <= c; k << 1) {
            int w2 = k * w;
            int v2 = k * v;
            for (int j = C; j >= w2; --j) {
                dp[j] = max(dp[j], dp[j - w2] + v2);
            }
            c -= k;
        }
        if (c > 0) {
            int w3 = c * w;
            int v3 = c * v;
            for (int j = C; j >= w3; --j) {
                dp[j] = max(dp[j], dp[j - w3] + v3);
            }
        }
    }
    cout << dp[C] << endl;
    return 0;
}
