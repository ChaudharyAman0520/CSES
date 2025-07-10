#include<bits/stdc++.h>
using namespace std;
unordered_set<string> st;
vector<bool> visited;
void permutations(string s,string path)
{
    if(path.size()==s.size())
    {
        st.insert(path);
    }
    for(int i=0;i<s.size();i++)
    {
        if(visited[i]==false)
        {
            path+=s[i];
            visited[i]=true;
            permutations(s,path);
            visited[i]=false;
            path=path.substr(0,path.size()-1);
        }
    }
}
main()
{
    string s,t="";
    cin>>s;
    visited.assign(s.size(),false);
    permutations(s,t);
    cout<<st.size()<<endl;
    vector<string> v(st.begin(),st.end());
    sort(v.begin(),v.end());
    for(auto i:v)
    {
        cout<<i<<endl;
    }
}
