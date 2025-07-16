#include<bits/stdc++.h>
#define int long long
using namespace std;
bool canMake(int t,vector<int>&v,int time)
{
    int amt=0;
    for(auto i:v)
    {
        amt+=time/i;
    }
    return amt>=t;
}
main()
{
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int L=1,R=t**min_element(v.begin(),v.end()),mid;
    while(L+1<R)
    {
        mid=L+(R-L)/2;
        if(canMake(t,v,mid))
        {
            R=mid;
        }
        else
        {
            L=mid;
        }
    }
    cout<<R<<endl;
}