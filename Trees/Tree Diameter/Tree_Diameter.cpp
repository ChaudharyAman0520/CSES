#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<int,int> bfs(vector<vector<int>>&tree,vector<int>&visited,int src)
{
    queue<pair<int,int>> q;
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
    vector<vector<int>> tree(n+1);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    vector<int> visited(n+1,0);
    pair<int,int> p=bfs(tree,visited,1);
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    p=bfs(tree,visited,p.first);
    cout<<p.second<<endl;
}