#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int d[N];
int main()
{
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    while (i < a.size())
    {
        if (a[i] == a[j])
        {
            i++;
            j++;
            if (j == b.size())
            {
                cout << i - j + 1;
                j = d[j-1];
            }
        }
        else
        {
            if (j > 0)
            {
                j = d[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return 0;
}