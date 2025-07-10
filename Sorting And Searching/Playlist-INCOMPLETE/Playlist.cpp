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
    unordered_map<int,int> hash;
    int start=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(hash.find(v[i])==hash.end())
        {
            hash[v[i]]=i;
        }
        else
        {
            ans=max(ans,i-start);
            cout<<"I = "<<i<<" Ans = "<<ans<<endl;
            start=hash[v[i]]+1;
            hash[v[i]]=i;
        }
    }
    cout<<ans<<endl;
}