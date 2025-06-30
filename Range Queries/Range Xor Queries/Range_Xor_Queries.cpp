#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> segtree;
void build(vector<int>&v,int i,int L,int R)
{
    if(L==R)
    {
        segtree[i]=v[L];
        // cout << "build(i=" << i << ", L=" << L << ", R=" << R << ") => " << segtree[i] << endl;
    }
    else
    {
        int M=(L+R)/2;
        build(v,i*2,L,M);
        build(v,i*2+1,M+1,R);
        segtree[i]=segtree[2*i]^segtree[2*i+1];
    }
}
int XOR(int i,int l,int r,int L,int R)
{
    if(l>R||L>r)
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
        return XOR(2*i,l,M,L,R)^XOR(2*i+1,M+1,r,L,R);
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
    // for(auto i:segtree)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<XOR(1,1,n,x,y)<<endl;;
    }
}