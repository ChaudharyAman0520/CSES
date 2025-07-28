#include<bits/stdc++.h>
using namespace std;
int up[200001][30];
int ans_query(int node,int jumps)
{
    for(int i=0;i<30;i++)
    {
        if(jumps&(1<<i))
        {
            node=up[node][i];
            if(node==-1)
            {
                break;
            }
        }
    }
    return node;
}
main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        up[i][0]=x;
    }
    for(int i=1;i<30;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(up[j][i-1]!=-1)
            {
                up[j][i]=up[up[j][i-1]][i-1];
            }
            else
            {
                up[j][i]=-1;
            }
        }
    }
    while(q--)
    {
        int x,k;
        cin>>x>>k;
        cout<<ans_query(x,k)<<"\n";
    }
}