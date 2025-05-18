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
    return d.back();
}
int main()
{
    int n;
    cin>>n;
    string ans;
    cin>>ans;
    for(int i=1;i<n;i++){
        string s;
        cin>>s;
        string suf=ans.substr(max(0,(int)ans.size()-(int)s.size()));
        string tmp=s+"#"+suf;
        int len=get_d(tmp);
        ans+=s.substr(len);
    }
    cout<<ans<<endl;
    return 0;
}
