#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n,k;
    cin>>n>>k;
    int x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<int> v(n);
    v[0]=x;
    for(int i=1;i<n;i++)
    {
        v[i]=(v[i-1]*a+b)%c;
    }
    // for(auto i:v)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    int sum=0;
    int ans=0;
    for(int i=0;i<k;i++)
    {
        sum+=v[i];
    }
    ans=sum;
    for(int i=k;i<n;i++)
    {
        sum-=v[i-k];
        sum+=v[i];
        ans=ans^sum;
    }
    cout<<ans<<endl;
}