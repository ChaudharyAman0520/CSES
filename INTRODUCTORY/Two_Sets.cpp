#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    vector<int> first;
    vector<int> second;
    int sum1=0;
    int sum2=0;
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(sum1<sum2)
        {
            first.push_back(i);
            sum1+=i;
        }
        else
        {
            second.push_back(i);
            sum2+=i;
        }
    }
    if(sum1==sum2)
    {
        flag=true;
    }
    if(flag)
    {
        cout<<"YES"<<endl;
        cout<<first.size();
        for(auto i:first)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<second.size();
        for(int i:second)
        {
            cout<<i<<" ";
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
}