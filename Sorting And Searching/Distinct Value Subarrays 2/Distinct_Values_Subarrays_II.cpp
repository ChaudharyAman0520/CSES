#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    map<int,int> mp;
    int L=0,R=0,ans=0;
    while(R<n)
    {
        mp[v[R]]++;
        while(L<n&&mp.size()>target)
        {
            mp[v[L]]--;
            if(mp[v[L]]==0)
            {
                mp.erase(v[L]);
            }
            L++;
        }
        ans+=R-L+1;
        R++;
    }
    cout<<ans<<endl;
}