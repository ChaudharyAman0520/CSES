#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int, vector<int>>&v,vector<int>&grayset,vector<int>&blackset,int curr,int parent,unordered_map<int,int>ans)
{
	grayset[curr]=1;
	ans[curr]=parent;
	for(auto i:v[curr])
	{
		if(blackset[i]==1)
		{
			continue;
		}
		if(grayset[i]==1)
		{
			if(ans.size()>=3)
			{
				cout<<ans.size()+1<<endl;
				while(ans[i]!=-1)
				{
					cout<<ans[i]<<" ";
					i=ans[i];
				}
				exit(0);
			}
		}
		dfs(v,grayset,blackset,i,curr,ans);
		blackset[i]=1;
		grayset[i]=0;
	}
}

main()
{
	int n,m;
	cin>>n>>m;
	unordered_map<int, vector<int>>v;
	for(int i=1;i<=m;i++)
	{
		int s,e;
		cin>>s>>e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	//~ for(auto i:v)
	//~ {
		//~ cout<<i.first<<"->";
		//~ for(auto j:i.second)
		//~ {
			//~ cout<<j<<"->";
		//~ }
		//~ cout<<endl;
	//~ }
	vector<int> grayset(n+1,0);
	vector<int> blackset(n+1,0);
	for(int i=1;i<=n;i++)
	{
		if(blackset[i]==0)
		{
			unordered_map<int,int> ans;
			ans[i]=-1;
			dfs(v,grayset,blackset,i,-1,ans);
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
