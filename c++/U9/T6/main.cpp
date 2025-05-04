#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], sz = 0;
void push(int x)
{
    a[++sz] = x;
    int id = sz;
    while (id > 1 && a[id] > a[id / 2])
    {
        swap(a[id], a[id / 2]);
        id /= 2;
    }
}
int get()
{
    int res = a[1];
    a[1] = a[sz--];
    int id = 1;
    while (id * 2 <= sz)
    {
        id *= 2;
        if (id + 1 <= sz && a[id] < a[id + 1])
            id++;
        if (a[id] <= a[id / 2])
            break;
        swap(a[id], a[id / 2]);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        push(x);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << get() << " ";
    }
    cout << endl;
    return 0;
}