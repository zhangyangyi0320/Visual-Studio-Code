#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<pair<int, pair<int, int>>> e(m);
    for (int i = 0; i < m; i++)
    {
        cin>>e[i].second.first>>e[i].second.second>>e[i].first;
    }
    sort(e.begin(), e.end());
    return 0;
}