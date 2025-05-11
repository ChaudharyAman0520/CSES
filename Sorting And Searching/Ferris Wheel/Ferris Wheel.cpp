#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int n,x;
	cin>>n>>x;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int ans=0;
	int i=0,j=n-1;
	while(i<=j)
	{
		if(i==j)
		{
			ans++;
			break;
		}
		if(v[j]+v[i]>x)
		{
			ans++;
			j--;
		}
		else
		{
			ans++;
			j--;
			i++;
		}
	}
	cout<<ans<<endl;
}
