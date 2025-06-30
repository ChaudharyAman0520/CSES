#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    int div=5;
    int ans=0;
    while(n/div>=1)
    {
        ans+=n/div;
        div*=5;
    }
    cout<<ans<<endl;
}