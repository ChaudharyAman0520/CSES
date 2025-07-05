#include<bits/stdc++.h>
#define int long long
using namespace std;
set<vector<int>> tree;
int up[200001][31];
void binary_lift(int src,int parent)
{
    up[src][0]=parent;
    for(int i=1;i<31;i++)
    {
        if(up[src][i-1]!=-1)
        {
            up[src][i]=up[up[src][i-1]][i-1];
        }
        else
        {
            up[src][i]=-1;
        }
    }
    for(auto i:tree[src])
    {
        if(i!=parent)
        {
            binary_lift(i,src);
        }
    }
}
int ans_query(int node,int jumps)
{
    if(node==-1||jumps==0)
    {
        return node;
    }
    for(int i=30;i>=0;i--)
    {
        if(jumps>=(1<<i))
        {
            return ans_query(up[node][i],jumps-(1<<i));
        }
    }
    return -1;
}
main()
{
    int n,q;
    cin>>n>>q;
    tree.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        tree[x].insert(i);
        tree[i].insert(x);
    }
    for(auto i:tree)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    binary_lift(1,-1);
    while(q--)
    {
        int node,k;
        cin>>node>>k;
        cout<<ans_query(node,k)<<endl;
    }
}