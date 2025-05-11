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
	sort(v.begin(),v.end());
	int targ;
	targ=v[n/2];
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=abs(targ-v[i]);
	}
	cout<<ans<<endl;
}
