#include <bits/stdc++.h>

using namespace std;

const int N = 6E3+10;
vector<int> ve[N];
int h[N], vis[N], n,f[N][2];
void dfs(int x) {
    f[x][0] = 0;
    f[x][1] = h[x];
    for (int j = 0; j < ve[x].size(); j++) {
        int y = ve[x][j];
        dfs(y);
        f[x][0] += max(f[y][0], f[y][1]);
        f[x][1] += f[y][0];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i < n; i++) {
        int l,k;
        cin >> l >> k;
        ve[k].push_back(l);
        vis[l] = 1;
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }
    dfs(root);
    cout << max(f[root][0], f[root][1]);
    return 0;
}