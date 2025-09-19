#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int L=0,R=0,ans=0;
    unordered_map<int,int> mp;
    while(R<n)
    {
        mp[v[R]]++;
        while(mp[v[R]]>1)
        {
            mp[v[L]]--;
            L++;
        }
        ans+=R-L+1;
        R++;
    }
    cout<<ans<<endl;
}