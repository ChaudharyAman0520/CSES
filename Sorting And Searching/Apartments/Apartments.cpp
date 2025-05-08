#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end() 
#define sortv(x) sort(all(x))     
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
	sortv(applicants);
	sortv(apartments);
	int ans=0;
	int i=0,j=0;
	while(i<n&&j<m)
	{
		if(apartments[i]>applicants[j]-k&&apartments[i]<applicants[j]+k)
		{
			ans++;
			i++;
			j++;
		}
		else if(apartments[j]<applicants[i]-k)
		{
			j++;
		}
		else
		{
			i++;
		}
	}
	cout<<ans<<endl;
}
