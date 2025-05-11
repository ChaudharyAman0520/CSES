#include<bits/stdc++.h>
#define int long long     
using namespace std;
main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> applicants(n);
	vector<int> apartments(m);
	for(int i=0;i<n;i++)
	{
		cin>>applicants[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>apartments[i];
	}
	sort(applicants.begin(),applicants.end());
	sort(apartments.begin(),apartments.end());
	int ans=0;
	int i=0,j=0;
	while(i<m&&j<n)
	{
		if(apartments[i]>=applicants[j]-k&&apartments[i]<=applicants[j]+k)
		{
			ans++;
			i++;
			j++;
		}
		else if(apartments[i]<applicants[j]-k)
		{
			i++;
		}
		else if(applicants[j]+k<apartments[i])
		{
			j++;
		}
	}
	cout<<ans<<endl;
}
