#include<bits/stdc++.h>
using namespace std;
int v;
vector<long long> coins;
vector<bool>ready;
vector<long long> value;
long long sums(long long n)
{
	if(n<0)
	{
		return LLONG_MAX;
	}
	if(n==0)
	{
		return 0;
	}
	if(ready[n]==true)
	{
		return value[n];
	}
	long long ans=LLONG_MAX;
	for(auto i:coins)
	{
		long long subs=sums(n-i);
		if(subs!=LLONG_MAX)
		ans=min(subs+1,ans);
	}
	ready[n]=true;
	value[n]=ans;
	return ans;
}
main()
{
	long long c;
	cin>>v>>c;
	for(int i=1;i<=v;i++)
	{
		long long x;
		cin>>x;
		coins.push_back(x);
	}
	ready.resize(c+1,false);
    value.resize(c+1,0);
	if(sums(c)==LLONG_MAX)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<sums(c)<<endl;
	}
}
