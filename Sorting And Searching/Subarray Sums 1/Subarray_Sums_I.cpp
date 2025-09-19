#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int L=0,R=0,cnt=0,curr=0;
    while(R<n)
    {
        curr+=v[R];
        while(curr>=target)
        {
            if(curr==target)
            {
                cnt++;
            }
            curr-=v[L];
            L++;
        }
        R++;
    }
    cout<<cnt<<endl;
}