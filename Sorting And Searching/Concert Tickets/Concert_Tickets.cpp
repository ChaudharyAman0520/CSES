#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int  n,m;
    cin>>n>>m;
    multiset<int> mst;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mst.insert(x);
    }
    while(m--)
    {
        int custprice;
        cin>>custprice;
        auto it=mst.upper_bound(custprice);
        if(it==mst.begin())
        {
            cout<<-1<<endl;
        }
        else
        {
            it--;
            cout<<*it<<endl;
            mst.erase(it);
        }
    }
}