#include <bits/stdc++.h>

using namespace std;

int n, d;
int ans[1010], tmp[1010];
vector<int> son[1010];
void dfs(int node, int depth)
{
    tmp[depth] = node;
    ans[node] = depth > d ? tmp[depth - d] : -1;
    for (int x : son[node])
    {
        dfs(x, depth + 1);
    }
}
int main()
{
    cin >> n >> d;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        son[x].push_back(i);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}