#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
	int n,q;
	cin>>n>>q;
	int v[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	int pref[n+1];
	pref[1]=v[1];
	for(int i=2;i<=n;i++)
	{
		pref[i]=pref[i-1]+v[i];
	}
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		cout<<pref[b]-(a-1==0?0:pref[a-1])<<endl;
	}
}
