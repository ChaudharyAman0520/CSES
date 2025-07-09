#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
vector<int> ans;
pair<int,int> bfs(int src,int n)
{
    queue<pair<int,int>> q;
    vector<int> visited(n+1,0);
    q.push({src,0});
    visited[src]=1;
    pair<int,int> it;
    while(q.empty()==false)
    {
        it=q.front();
        q.pop();
        for(auto i:tree[it.first])
        {
            if(visited[i]==0)
            {
                q.push({i,it.second+1});
                visited[i]=1;
                ans[i]=max(ans[i],it.second+1);
            }
        }
    }
    return it;
}
main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    tree.resize(n+1);
    ans.assign(n+1,-1);
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    auto it1=bfs(1,n);
    auto it2=bfs(it1.first,n);
    bfs(it2.first,n);
    // cout<<it1.first<<endl;
    // cout<<it2.first<<" "<<it2.second<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}