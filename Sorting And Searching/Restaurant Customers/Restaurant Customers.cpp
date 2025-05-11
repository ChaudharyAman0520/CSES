#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int n;
	cin>>n;
	vector<int> start(n),leave(n);
	for(int i=0;i<n;i++)
	{
		cin>>start[i];
		cin>>leave[i];
	}	
	sort(start.begin(),start.end());
	sort(leave.begin(),leave.end());
	int ans=0,maxans=0;
	int i=0,j=0;
	while(i<n&&j<n)
	{
		if(start[i]>leave[j])
		{
			ans--;
			j++;
		}
		else
		{
			ans++;
			i++;
		}
		maxans=max(ans,maxans);
	}
	cout<<maxans<<endl;
}
