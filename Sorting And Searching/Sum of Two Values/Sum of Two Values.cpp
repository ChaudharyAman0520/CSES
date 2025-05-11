#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int n,x;
	cin>>n>>x;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int i=0,j=n-1;
	while(i<j)
	{
		int sum=v[i]+v[j];
		if(sum==x)
		{
			cout<<i+1<<" "<<j+1<<endl;
			exit(0);
		}
		else if(sum>x)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
