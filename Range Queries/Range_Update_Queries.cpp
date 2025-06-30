#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> segtree;
vector<int> lazy;
void push(int i, int l, int r) 
{
    if (lazy[i]!=0) 
    {
        segtree[i]+=(r-l+1)*lazy[i];
        if (l!=r) 
        {
            lazy[2*i]+=lazy[i];
            lazy[2*i+1]+=lazy[i];
        }
        lazy[i]=0;
    }
}
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
void update(int i,int l,int r,int ql,int qr,int val) 
{
    push(i,l,r);
    if (r<ql||l>qr) 
    {
        return;
    }
    if (ql<=l&&r<=qr) 
    {
        lazy[i]+=val;
        push(i,l,r);
        return;
    }
    int M=(l+r)/2;
    update(2*i,l,M,ql,qr,val);
    update(2*i+1,M+1,r,ql,qr,val);
    segtree[i]=segtree[2*i]+segtree[2*i+1];
}
int query(int i,int l,int r,int k) 
{
    push(i,l,r);
    if(l==r) 
    {
        return segtree[i];
    }
    int M=(l+r)/2;
    if (k<=M)
    { 
        return query(2*i,l,M,k);
    }
    else 
    {
        return query(2*i+1,M+1,r,k);
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
    lazy.assign(4*n+1,0);
    build(v,1,1,n);
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int a,b,u;
            cin>>a>>b>>u;
            update(1,1,n,a,b,u);
        }
        else
        {
            int k;
            cin>>k;
            cout<<query(1, 1, n, k)<<endl;
        }
    }
}