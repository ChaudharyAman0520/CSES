#include<bits/stdc++.h>
using namespace std;
static bool cmp(pair<char,int> p1, pair<char,int> p2)
{
    return p2.second<p1.second;
}
main()
{
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    for(auto i:s)
    {
        mp[i]++;
    }
    int cnt=0;
    char center='~';
    for(auto i:mp)
    {
        if(i.second%2!=0)
        {
            center=i.first;
            cnt++;
        }
    }
    if(cnt>1)
    {
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    vector<pair<char,int>> v(mp.begin(),mp.end());
    sort(v.begin(),v.end(),cmp);
    // for(auto i:v)
    // {
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    string prefix="";
    string suffix="";
    for(auto i:v)
    {
        if(i.second%2!=0)
        {
            continue;
        }
        prefix+=string(i.second/2,i.first);
        suffix=string(i.second/2,i.first)+suffix;
    }
    if(cnt==1)
    {
        cout<<prefix<<string(mp[center],center)<<suffix<<endl;
    }
    else if(cnt==0)
    {
        cout<<prefix<<suffix<<endl;
    }
}