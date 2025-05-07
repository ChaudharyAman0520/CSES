#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<int>> mat(n+1,vector<int>(n+1,LLONG_MAX));
	for(int i=1;i<=n;i++) 
	{
        mat[i][i]=0;
    }
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		mat[a][b]=min(mat[a][b],c);
		mat[b][a]=min(mat[b][a],c);
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(mat[i][k]!=LLONG_MAX&&mat[k][j]!=LLONG_MAX)
				mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
			}
		}
	}
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		if(mat[a][b]==LLONG_MAX)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<mat[a][b]<<endl;
		}
	}
		
}
