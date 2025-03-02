#include <bits/stdc++.h>

using namespace std;

int sum = 0, n;

struct node
{
    int dps, hp;
    double t;
} a[30];

bool cmp(node a, node b)
{
    return a.t > b.t;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].dps >> a[i].hp;
        a[i].t = a[i].dps * 1.0 / a[i].hp;
        sum += a[i].dps;
    }
    sort(a, a + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int m = a[i].hp;
        while (m > 0)
        {
            m--;
            ans += sum;
        }
        sum -= a[i].dps;
    }
    cout << ans;
    return 0;
}
