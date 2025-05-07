#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
main()
{
	int n;
	cin>>n;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=(2*ans)%M;
	}
	cout<<ans<<endl;
}
