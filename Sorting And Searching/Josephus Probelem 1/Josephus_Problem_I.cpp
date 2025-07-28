#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    bool kill=false;
    vector<int> ans;
    while(q.size()!=1)
    {
        int i=q.front();
        q.pop();
        if(kill==false)
        {
            q.push(i);
        }
        else
        {
            ans.push_back(i);
        }
        kill=!kill;
    }
    ans.push_back(q.front());
    q.pop();
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}