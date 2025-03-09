#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int to[4][2]= {-1,0,0,1,1,0,0,-1};
int n,m,t;
char mp[N][N]; //.为草地  *为障碍
int a[N][N];
int bx,by,ex,ey;
int res;
int dp[N][N][20];
int dfs(int x,int y,int step)
{
    if(step>t)   //剪枝1
        return 0;
    if(step+fabs(x-ex)+fabs(y-ey)>t)  //剪枝2，走到(x,y),已经走了T秒，若(x,y)到目标点(ex,ey)的最短距离花费的总时间>t,则直接返回
        return 0;
    if(dp[x][y][step])
        return dp[x][y][step];
    if(x==ex&&y==ey&&step==t)  //奶牛总是在移动，结束条件是刚好走了t秒 ,可以重复走
        return 1;
    int sum=0;
    for(int i=0; i<4; i++)
    {
        int tx=x+to[i][0];
        int ty=y+to[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==1)
            sum+=dfs(tx,ty,step+1); 
    }
    dp[x][y][step]=sum;
    return sum;
}
int main()
{
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    cin>>n>>m>>t;     //地图n*m t秒 (R1,C1)-->(R2,C2)
    for(int i=0; i<n; i++)
        cin>>mp[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mp[i][j]=='*')
                a[i+1][j+1]=0;
            else
                a[i+1][j+1]=1;   //1能走、0不能走
        }
    }
    cin>>bx>>by>>ex>>ey;
    cout<<dfs(bx,by,0);
    return 0;
}