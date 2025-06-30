#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> segtree;
void build(vector<int>&v,int i,int L,int R)
{
    if(L==R)
    {
        segtree[i]=v[L];
    }
    else
    {
        int M=(L+R)/2;
        build(v,2*i,L,M);
        build(v,2*i+1,M+1,R);
        segtree[i]=segtree[2*i]+segtree[2*i+1];
    }
}
int sum(int i,int l,int r,int L,int R)
{
    if(l>R||r<L)
    {
        return 0;
    }
    if(L<=l&&r<=R)
    {
        return segtree[i];
    }
    else
    {
        int M=(l+r)/2;
        return sum(2*i,l,M,L,R)+sum(2*i+1,M+1,r,L,R);
    }
}
int update(int i,int pos,int l,int r,int u)
{
    if(l==r)
    {
        int val=u-segtree[i];
        segtree[i]=u;
        return val;
    }
    else
    {
        int M=(l+r)/2;
        int val,ret;
        if(pos<=M)
        {
            val=update(2*i,pos,l,M,u)+segtree[i];
            ret=val-segtree[i];
            segtree[i]=val;
        }
        else
        {
            val=update(2*i+1,pos,M+1,r,u)+segtree[i];
            ret=val-segtree[i];
            segtree[i]=val;
        }
        return ret;
    }
}
main()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    segtree.assign(4*n+1,0);
    build(v,1,1,n);
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int k,u;
            cin>>k>>u;
            update(1,k,1,n,u);
        }
        else
        {
            int a,b;
            cin>>a>>b;
            cout<<sum(1,1,n,a,b)<<endl;
        }
    }
}