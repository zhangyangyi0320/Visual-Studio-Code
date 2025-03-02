#include <bits/stdc++.h>

using namespace std;

struct node
{
    string n;
    string p;
    int c;
} a[110];

bool cmp(node a, node b)
{
    if (a.p != b.p)
    {
        return a.p < b.p;
    }
    else
    {
        return a.n < b.n;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> a[j].n >> a[j].p >> a[j].c;
        }
        sort(a, a + m, cmp);
        string q = a[0].n, p = a[0].p;
        int k = a[1].c;
        cout << q << endl;
        for (int j = 1; j < m; j++)
        {
            if (a[j].p == p)
            {
                cout << "   |----" << q << "(" << k << ")" << endl;
                q = a[j].n;
                p = a[j].p;
                k = a[j].c;
                cout << p << endl;
            }
            else if (a[i].n != q)
            {
                cout << "   |----" << q << "(" << k << ")" << endl;
                q = a[j].n;
                k = a[j].c;
            }
            else
            {
                k += a[j].c;
            }
            cout << "   |----" << q << "(" << k << ")" << endl;
            if (n)
            {
                cout << endl;
            }
        }
    }
    return 0;
}