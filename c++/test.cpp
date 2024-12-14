#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100005];
struct node
{
    double x;
    double y;
    double z;
};
node a[2005];
node lss[500005];
bool cmp(node x, node y)
{
    return x.z < y.z;
}
int find(int x)
{
    if (x == arr[x])
        return x;
    return arr[x] = find(arr[x]);
}
void hb(int x, int y)
{
    int xx = find(x);
    int yy = find(y);
    arr[xx] = yy;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            t++;
            lss[t].x = i;
            lss[t].y = j;
            lss[t].z = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
        }
    }
    int w = 0;
    sort(lss + 1, lss + 1 + t, cmp);
    for (int i = 1; i <= t; i++)
    {
        if (find(lss[i].x) != find(lss[i].y))
        {
            hb(lss[i].x, lss[i].y);
            w++;
            if (w == n - m)
            {
                printf("%.2f", lss[i].z);
                return 0;
            }
        }
    }
    return 0;
}
