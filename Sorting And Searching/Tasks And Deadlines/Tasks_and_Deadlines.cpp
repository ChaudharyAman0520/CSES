#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    // for(auto i:v)
    // {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    int ans=0;
    int curr=0;
    for(int i=0;i<n;i++)
    {
        curr+=v[i].first;
        ans+=v[i].second-curr;
    }
    cout<<ans<<endl;
}