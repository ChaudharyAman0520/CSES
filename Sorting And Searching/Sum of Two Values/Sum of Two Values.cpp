#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,x;
	cin>>n>>x;
	vector<pair<long long,long long>> v;
	for(int i=0;i<n;i++)
	{
		long long l;
		cin>>l;
		v.push_back({l,i+1});
	}
	//~ for(auto i:v)
	//~ {
		//~ cout<<i.first<<" "<<i.second<<endl;
	//~ }
	sort(v.begin(),v.end());
	int i=0,j=n-1;
	while(i<j)
	{
		int sum=v[i].first+v[j].first;
		if(sum==x)
		{
			cout<<v[i].second<<" "<<v[j].second<<endl;
			return 0;
		}
		else if(sum<x)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
