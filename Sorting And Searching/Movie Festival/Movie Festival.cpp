#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int n;
	cin>>n;
	vector<pair<int,int>>v;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v.push_back({b,a});
	}
	sort(v.begin(),v.end());
	int finish=0,ans=0;
	for(auto i:v)
	{
		if(i.second>=finish)
		{
			ans++;
			finish=i.first;
		}
	}
	cout<<ans<<endl;
}
