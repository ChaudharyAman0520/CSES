#include<bits/stdc++.h>
using namespace std;
void TOH(int n,int from,int to,int aux)
{
	if(n==0)
	{
		return;
	}
	TOH(n-1,from,aux,to);
	cout<<from<<" "<<to<<endl;
	TOH(n-1,aux,to,from);
}
main()
{
	int n;
	cin>>n;
	cout<<pow(2,n)-1<<endl;
	TOH(n,1,3,2);
}
