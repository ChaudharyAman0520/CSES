#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin>>n;
    int sum=(n*(n+1))/2;
    if(sum%2!=0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        int target=sum/2;
        set<int> set1;
        int t=n;
        while(target!=0)
        {
            if(target-n>=0)
            {
                target-=n;
                set1.insert(n);
            }
            n--;
        }
        set<int> set2;
        for(int i=1;i<=t;i++)
        {
            if(set1.find(i)==set1.end())
            {
                set2.insert(i);
            }
        }
        cout<<set1.size()<<endl;
        for(auto i:set1)
        {
            cout<<i<<" ";
        }
        cout<<endl<<set2.size()<<endl;
        for(auto i:set2)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}