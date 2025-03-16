#include<bits/stdc++.h>
using namespace std;

int c,r,cnt;
int kx,ky,hx,hy;
int b[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
char a[160][160];

void dfs(int x,int y){
    if(x==hx && y==hy){
        cnt++;
        return;
    }
    for(int i=0;i<8;i++){
        int nx=x+b[i][0];
        int ny=y+b[i][1];
        if(nx>=1 && nx<=c && ny>=1 && ny<=r && a[nx][ny]!='*'){
            a[nx][ny]='*';
            dfs(nx,ny);
        }
    }
    cnt++;
}

int main(){
    cin>>c>>r;
    for(int i=1;i<c;i++){
        for(int j=1;j<r;j++){
            cin>>a[i][j];
            if(a[i][j]=='K'){
                kx=i;
                ky=j;
            }else if(a[i][j]=='H'){
                hx=i;
                hy=j;
            }
        }
    }
    dfs(kx,ky);
    cout<<cnt;
    return 0;
}