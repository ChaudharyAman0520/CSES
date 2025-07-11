#include<bits/stdc++.h>
#include <chrono>
#define int long long
using namespace std;
using namespace std::chrono;
main()
{
    auto start1 = high_resolution_clock::now();
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    map<int,int> hash;
    int start=0;
    int ans=0;
    int i=0;
    for(i=0;i<n;i++)
    {
        if(hash.find(v[i])==hash.end())
        {
            hash[v[i]]=i;
        }
        else
        {
            ans=max(ans,i-start);
            if(hash[v[i]]>=start)
            {
                start=hash[v[i]]+1;
            }
            hash[v[i]]=i;
        }
    }
    cout<<max(ans,i-start)<<endl;
    auto end = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(end - start1).count();
    cout<<ms<<endl;
}