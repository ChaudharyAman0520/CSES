#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
int up[200001][20];
int lvl[200001];
void binary_lift(int curr,int parent,int currlvl)
{
    lvl[curr]=currlvl;
    up[curr][0]=parent;
    for(int i=1;i<20;i++)
    {
        if(up[curr][i-1]!=-1)
        {
            up[curr][i]=up[up[curr][i-1]][i-1];
        }
        else
        {
            up[curr][i]=-1;
        }
    }
    for(auto i:tree[curr])
    {
        if(i!=parent)
        {
            binary_lift(i,curr,currlvl+1);
        }
    }
}
int ans_query(int node,int jumps)
{
    if(node==-1||jumps==0)
    {
        return node;
    }
    for(int i=19;i>=0;i--)
    {
        if(jumps>=(1<<i))
        {
            return ans_query(up[node][i],jumps-(1<<i));
        }
    }
}
int LCA(int p,int q)
{
    if(lvl[p]<lvl[q])
    {
        swap(p,q);
    }
    for(int i=19;i>=0;i--)
    {
        if(lvl[p]-(1<<i)>=lvl[q])
        {
            p=up[p][i];
        }
    }
    if(p==q)
    {
        return p;
    }
    for(int i=19;i>=0;i--)
    {
        if(up[p][i]!=up[q][i])
        {
            p=up[p][i];
            q=up[q][i];
        }
    }
    return up[p][0]; // Or up[q][0];
}
main()
{
    int n,q;
    cin>>n>>q;
    tree.resize(n+1);
    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;
        tree[a].push_back(i);
        tree[i].push_back(a);
    }
    binary_lift(1,-1,0);
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<=19;j++)
    //     {
    //         cout<<up[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // while(q--)
    // {
    //     int x,y;
    //     cin>>x>>y;
    //     cout<<ans_query(x,y)<<endl;
    // }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
}