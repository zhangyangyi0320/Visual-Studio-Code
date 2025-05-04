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
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    return 0;
}