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
    multiset<int> st;
    st.insert(v[0]);
    for(int i=1;i<n;i++)
    {
        auto it=st.upper_bound(v[i]);
        if(it==st.end())
        {
            st.insert(v[i]);
        }
        else
        {
            st.erase(it);
            st.insert(v[i]);
        }
    }
    cout<<st.size()<<endl;
}