#include<bits/stdc++.h>
#define int size_t
using namespace std;
vector<int> toposort(unordered_map<int,vector<int>>&v,int V)
{
	vector<int> ans;
	int indeg[V+1]={0};
	for(auto i:v)
	{
		for(auto j:i.second)
		{
			indeg[j]++;
		}
	}
	queue<int>q;
	for(int i=1;i<=V;i++)
	{
		if(indeg[i]==0)
		{
			q.push(i);
		}
	}
	while(q.empty()==false)
	{
		int node=q.front();
		q.pop();
		ans.push_back(node);
		for(auto i:v[node])
		{
			indeg[i]--;
			if(indeg[i]==0)
			{
				q.push(i);
			}
		}
	}
	return ans;
}
using namespace std;
main()
{
	int n,m;
	cin>>n>>m;
	unordered_map<int,vector<int>>adj;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}	
	//~ for(auto i:adj)
	//~ {
		//~ cout<<i.first<<"->";
		//~ for(auto j:i.second)
		//~ {
			//~ cout<<j<<"->";
		//~ }
		//~ cout<<endl;
	//~ }
	//~ for(int i=1;i<=n;i++)
	//~ {
		//~ if(adj.find(i)==adj.end())
		//~ {
			//~ adj[i]={};
		//~ }
	//~ }
	vector<int> ans=toposort(adj,n);
	if(ans.size()!=n)
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	else
	{
		for(auto i:ans)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
