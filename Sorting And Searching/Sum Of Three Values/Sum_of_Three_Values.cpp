#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int l;
        cin>>l;
        v.push_back({l,i+1});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-2;i++)
    {
        int targ=x-v[i].first;
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            if(v[j].first+v[k].first>targ)
            {
                k--;
            }
            else if(v[j].first+v[k].first<targ)
            {
                j++;
            }
            else
            {
                cout<<v[i].second<<" "<<v[j].second<<" "<<v[k].second<<endl;
                exit(0);
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
