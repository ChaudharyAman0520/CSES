#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e9+7;
main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        mp[v[i]]++;
    }
    long long ans=1;
    for(auto i:mp)
    {
        ans=((ans%M)*((i.second+1)%M))%M;
    }
    cout<<ans-1<<endl;
}