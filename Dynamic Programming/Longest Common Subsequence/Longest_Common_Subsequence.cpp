#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> dp;
main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v1(n+1),v2(m+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v1[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>v2[i];
    }
    dp=vector<vector<int>>(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> ans;
    int i=n;
    int j=m;
    while(i>0&&j>0)
    {
        if(dp[i][j]==dp[i-1][j])
        {
            i=i-1;
        }
        else if(dp[i][j]==dp[i][j-1])
        {
            j=j-1;
        }
        else if(dp[i-1][j-1]!=dp[i][j])
        {
            ans.push_back(v1[i]);
            i=i-1;
            j=j-1;
        }
    }
    cout<<dp[n][m]<<endl;
    reverse(ans.begin(),ans.end());
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}