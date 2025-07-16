#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<int,int> canSplit(vector<int>&v,int mid,int k)
{
    int cnt=0,curr=0;
    int i=0;
    while(i<v.size())
    {
        if(curr+v[i]>mid)
        {
            if(v[i]>mid)
            {
                return {0,1};
            }
            curr=0;
            cnt++;
        }
        else
        {
            curr+=v[i];
            i++;
        }
    }
    cnt++;
    if(cnt==k)
    {
        return {1,0};
    }
    else
    {
        if(cnt<k)
        {
            return {0,0};
        }
        else
        {
            return {0,1};
        }
    }
}
main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int L=0,R=0,mid;
    for(auto i:v)
    {
        R+=i;
    }
    while(L+1<R)
    {
        mid=L+(R-L)/2;
        auto it=canSplit(v,mid,k);
        if(it.first==1)
        {
            R=mid;
        }
        else
        {
            if(it.second==1)
            {
                L=mid;
            }
            else
            {
                R=mid;
            }
        }
    }
    cout<<R<<endl;
}