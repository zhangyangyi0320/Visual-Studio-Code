#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,r,a[160][160],b[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    cin>>c>>r;
    for(int i=1;i<c;i++){
        for(int j=1;j<r;j++){
            cin>>a[i][j];
        }
    }
    return 0;
}