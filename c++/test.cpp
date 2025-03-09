#include <bits/stdc++.h>

using namespace std;

char a[60][60];
int n, m, t, k, sum = 1, to[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y)
{
    for (int i = 0; i <= 3; i++)
    {
        int tx = x + to[i][0], ty = y + to[i][1];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] == '.')
        {
            sum++;
            a[tx][ty] = '#';
            dfs(tx, ty);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '@')
            {
                t = i;
                k = j;
            }
        }
    }
    dfs(t, k);
    cout << sum << endl;
    return 0;
}