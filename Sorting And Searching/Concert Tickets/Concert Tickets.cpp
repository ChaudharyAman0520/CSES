#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int n,m;
	cin>>n>>m;
	vector<int> price(n),custmax(m);
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	for(int j=0;j<m;j++)
	{
		cin>>custmax[j];
	}
	sort(price.begin(),price.end());
	int i=0,j=0;
	int prev=-1;
	while(j<m&&i<n)
	{
		if(price[i]<=custmax[j])
		{
			prev=price[i];
			i++;
		}
		else
		{
			cout<<prev<<endl;
			j++;
		}
	}
	if(j<m)
	{
		cout<<prev<<endl;
		j++;
	}	
	while(j<m)
	{
		cout<<-1<<endl;
		j++;
	}
}
