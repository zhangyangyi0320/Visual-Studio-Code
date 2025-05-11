#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        mp[x]=1;
    }
    int m;
    cin >> m;
    while(m--) {
        string x;
        cin >> x;
        if(mp.count(x)==0) {
            cout << "WRONG" << endl;
        } else if(mp[x]==1){
            cout << "OK" << endl;
            mp[x]++;
        } else {
            cout << "REPEAT" << endl;
        }
    }
    return 0;
}
