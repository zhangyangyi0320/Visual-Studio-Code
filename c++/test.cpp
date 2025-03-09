#include <bits/stdc++.h>

using namespace std;

int n;

struct node
{
    int id,pm1,pm2,pm;
}a[1010];

bool cmp(node a,node b)
{
    if(a.pm!=b.pm)
        return a.pm>b.pm;
    else if(a.pm2!=b.pm2)
        return a.pm2<b.pm2;
    return a.id<b.id;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        a[i].id=i;
        cin>>a[i].pm1>>a[i].pm2;
        a[i].pm=a[i].pm1-a[i].pm2;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
        cout<<a[i].id<<' ';
    return 0;
}