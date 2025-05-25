#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> a;
        int n;
        cin >> n;
        for (int i = 2; i * i < n; i++)
        {
            if (n % i == 0)
            {
                while (n % i == 0)
                {
                    n /= i;
                    a.push_back(i);
                }
            }
        }
        if (n > 1)
        {
            a.push_back(n);
        }
        for(int i = 0; i < a.size(); i++)
        {
            if(i == 0) cout << a[i];
            else cout << "*" << a[i];
        }
        cout << endl;
    }
    return 0;
}
