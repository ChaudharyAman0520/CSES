#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> segtree;
void build(vector<int>&v,int i,int l,int r)
{
    if(l==r)
    {
        segtree[i]=v[l];
    }
    else
    {
        int M=(l+r)/2;
        build(v,2*i,l,M);
        build(v,2*i+1,M+1,r);
        segtree[i]=min(segtree[2*i],segtree[2*i+1]);
    }
}
int minimum(int i,int l,int r,int L,int R)
{
    if(L>r||R<l)
    {
        return LLONG_MAX;
    }
    if(l>=L&&r<=R)
    {
        return segtree[i];
    }
    else
    {
        int M=(l+r)/2;
        return min(minimum(2*i,l,M,L,R),minimum(2*i+1,M+1,r,L,R));
    }
}
void update(int i,int pos,int l,int r,int val)
{
    if(l==r)
    {
        segtree[i]=val;
        return;
    }
    else
    {
        int M=(l+r)/2;
        if(pos<=M)
        {
            update(2*i,pos,l,M,val);
        }
        else
        {
            update(2*i+1,pos,M+1,r,val);
        }
        segtree[i]=min(segtree[2*i],segtree[2*i+1]);
        return;
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
    segtree.assign(4*n+1,LLONG_MAX);
    build(v,1,1,n);
    // for(auto i:segtree)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
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
            cout<<minimum(1,1,n,a,b)<<endl;
        }
    }
    // for(auto i:segtree)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
}