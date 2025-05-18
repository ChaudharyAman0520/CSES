#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int curr=1,last=0,round=0,i=0;
	bool flag=false;
	while(v.empty()==false)
	{
		flag=false;
		round++;
		if(v[i]==curr)
		{
			last=curr+1;
			v.erase(v.begin()+i);
			flag=true;
		}
		if(v[i]>curr&&flag==true)
		{
			v.erase(v.begin()+i);
			last=v[i]+1;
		}
		i++;
	}
}
