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
	long long sumc=0;
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		if(v[i]>sumc+1)
		{
			break;
		}
		sumc+=v[i];
	}
	cout<<sumc+1<<endl;
}
