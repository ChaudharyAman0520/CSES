#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int n;
	cin>>n;
	cout<<0<<endl;
	int s=0,k=8;
	for(int i=2;i<=n;i++)
	{
		int sq=i*i;
		cout<<(sq*(sq-1))/2-s<<endl;
		s=s+k;
		k=8*i;
	}
}
