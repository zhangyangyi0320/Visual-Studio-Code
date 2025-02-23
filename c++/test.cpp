#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];

int main()
{
    string a,b;
    cin>>a;
    b=a;
    reverse(b.begin(),b.end());
    for (int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < b.size(); j--)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<a.size()-dp[a.size()-1][b.size()-1];
    return 0;
}