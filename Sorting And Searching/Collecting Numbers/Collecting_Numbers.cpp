#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin>>n;
    vector<int> v(n+1),pos(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        pos[v[i]]=i;
    }
    int ans=0;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<pos[i]<<endl;
    // }
    for(int i=1;i<n;i++)
    {
        if(pos[i]>pos[i+1])
        {
            ans++;
        }
    }
    cout<<ans+1<<endl;
}