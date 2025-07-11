#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n,targ;
    cin>>n>>targ;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back({x,i+1});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            int k=j+1;
            int l=n-1;
            int comp=(targ-v[i].first)-v[j].first;
            while(k<l)
            {
                int sum=v[k].first+v[l].first;
                if(sum==comp)
                {
                    cout<<v[i].second<<" "<<v[j].second<<" "<<v[k].second<<" "<<v[l].second;
                    return 0;
                }
                else if(sum<comp)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}