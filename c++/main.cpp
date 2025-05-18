#include <bits/stdc++.h>
using namespace std;
int d[1000005];
int get_d(string &s)
{
    int n=s.size();
    vector<int> d(n);
    for(int i=1,j=0;i<n;)
    {
        if(s[i]==s[j])
        {
            d[i]=j+1;
            i++;
            j++;
        }
        else if(j)
        {
            j=d[j-1];
        }
        else
        {
            i++;
        }
    }
    return d;
}
int main()
{
    string A,B;
    cin>>A>>B;
    for(int i=1,j=0;i<=B.size();)
    {
        if(B[i]==B[j])
        {
            d[i]=j+1;
            i++;
            j++;
        }
        else if(j)
        {
            j=d[j-1];
        }
        else
        {
            i++;
        }
    }
    return 0;
}
