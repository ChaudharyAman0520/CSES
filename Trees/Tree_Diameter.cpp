#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    vector<int> tree[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    
}