#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
void dfs(int par,int root,vector<vector<int>>&tree)
{
    for(auto i:tree[root])
    {
        if(i!=par)
        {
            dfs(root,i,tree);
            dp[root]+=1+dp[i];
        }
    }
}
main()
{
    int n;
    cin>>n;
    dp.resize(n+1);
    vector<vector<int>> tree(n+1);
    for(int i=1;i<n;i++)
    {
        int x;
        cin>>x;
        tree[i+1].push_back(x);
        tree[x].push_back(i+1);
    }
    // for(auto i:tree)
    // {
    //     for(auto j:i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    dfs(0,1,tree);
    for(int i=1;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
}