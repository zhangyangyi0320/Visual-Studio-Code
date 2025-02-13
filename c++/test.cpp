#include <bits/stdc++.h>

using namespace std;

int dp[20][210];

struct node{
    int w;
    int c;
};

int main() {

    int V,N,T;
    cin>>V>>N>>T;
    vector<node> ve[20];
    for(int i=1;i<=N;i++){
        int W,C,P;
        cin>>W>>C>>P;
        ve[P].push_back({W,C});
    }

    for(int i=1;i<=T;i++){
        for(int j=0;j<=V;j++){
            dp[i][j]=dp[i-1][j];
            for(int k=0;k<ve[i].size();k++){
                if(j>=ve[i][k].w)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-ve[i][k].w]+ve[i][k].c);
            }
        }
    }

    cout<<dp[T][V]<<endl;

    return 0;
}