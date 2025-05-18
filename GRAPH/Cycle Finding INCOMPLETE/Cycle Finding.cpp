#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> Graph;
	for(int i=1;i<=m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		Graph.push_back({u,v,wt});
	}
	for(auto i:Graph)
	{
		cout<<i[0]<<i[1]<<i[2]<<endl;
	}
}
