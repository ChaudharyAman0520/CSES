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
    int sum1=0,sum2=0,ans=LLONG_MAX;
    for(int mask=0;mask<(1<<n);mask++)
    {
        sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i))
            {
                sum1+=v[i];
            }
            else
            {
                sum2+=v[i];
            }
        }
        ans=min(ans,abs(sum1-sum2));
    }
    cout<<ans<<endl;
}