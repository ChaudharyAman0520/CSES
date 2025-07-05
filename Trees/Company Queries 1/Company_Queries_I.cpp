#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
int up[200001][20];
void binary_lift(int curr,int parent)
{
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
            binary_lift(i,curr);
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
    binary_lift(1,-1);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<ans_query(x,y)<<endl;
    }
}