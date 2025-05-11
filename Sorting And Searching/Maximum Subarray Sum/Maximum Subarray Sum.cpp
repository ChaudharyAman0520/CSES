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
	int sum=0,maxsum=LLONG_MIN;
	for(int i=0;i<n;i++)
	{
		if(sum<0)
		{
			sum=0;
		}
		sum+=v[i];
		maxsum=max(sum,maxsum);
	}
	cout<<maxsum<<endl;
}
