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
    deque<int> dq;
    for(int i=0;i<k;i++)
    {
        if(dq.empty()==true)
        {
            dq.push_back(v[i]);
        }
        else
        {
            while(dq.empty()==false&&v[i]<dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(v[i]);
        }
    }
    int ans=dq.front();
    // cout<<ans<<endl;
    for(int i=k;i<n;i++)
    {
        if(dq.front()==v[i-k])
        {
            dq.pop_front();
        }
        while(dq.empty()==false&&v[i]<dq.back())
        {
            dq.pop_back();
        }
        dq.push_back(v[i]);
        ans=ans^dq.front();
    }
    cout<<ans<<endl;
}