#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    stack<int> st;
    for(int i=1;i<=n;i++)
    {
        // cout<<"INDEX "<<i<<endl;
        if(st.empty()==true)
        {
            cout<<0<<" ";
            st.push(i);
        }
        else
        {
            while(st.empty()==false&&v[i]<=v[st.top()])
            {
                st.pop();
            }
            if(st.empty()==true)
            {
                cout<<0<<" ";
            }
            else
            {
                cout<<st.top()<<" ";
            }
            st.push(i);
        }
    }
    // cout<<"EXIT"<<endl;
}