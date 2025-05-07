#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	cin>>n;
	for(int i=0;i<pow(2,n);i++)
	{
		int gray=i^(i>>1);
		//~ cout<<gray<<endl;
		bitset<65536>r(gray);
		string s=r.to_string();
		cout<<s.substr(65536-n)<<endl;
	}
}
