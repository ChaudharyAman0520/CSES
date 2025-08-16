#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    map<int,int> mp;
    int L=0,R=0;
    vector<int> ans;
    while(R<k)
    {
        mp[v[R]]++;
        R++;
    }
    ans.push_back(mp.size());
    while(R<v.size())
    {
        mp[v[R]]++;
        mp[v[L]]--;
        if(mp[v[L]]==0)
        {
            mp.erase(v[L]);
        }
        L++;
        R++;
        ans.push_back(mp.size());
    }
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}