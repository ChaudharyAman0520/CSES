#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=x;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(j-coins[i-1]>=0)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // cout<<"OUTPUT"<<endl;
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=x;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][x]<<endl;
}