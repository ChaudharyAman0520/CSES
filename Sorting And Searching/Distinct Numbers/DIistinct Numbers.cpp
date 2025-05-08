#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	cin>>n;
	vector<long long>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	long long prev=-1,ans=0;
	for(int i=0;i<n;i++)
	{
		if(v[i]!=prev)
		{
			ans++;
			prev=v[i];
		}
	}
	cout<<ans<<endl;
}
