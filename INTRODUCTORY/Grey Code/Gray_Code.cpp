#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	cin>>n;
	for(int i=0;i<(1<<n);i++)
	{
		int gray=i^(i>>1);
		string ans="";
		for(int j=n-1;j>=0;j--)
		{
			if(gray&(1<<j))
			{
				ans+='1';
			}
			else
			{
				ans+='0';
			}
		}
		cout<<ans<<endl;;
	}
}
